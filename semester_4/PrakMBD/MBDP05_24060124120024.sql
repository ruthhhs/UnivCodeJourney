-- === RESPONSI ===
-- nama	: Ruth Septriana Sipangkar
-- nim	: 24060124120024

use bankdb;

-- 1. vw_recent_high_value_transactions 
create or replace view vw_recent_high_value_transactions as
select * from transactions
where transaction_date >= sysdate()-30
and amount >= (select avg(amount) from transactions);

select * from vw_recent_high_value_transactions;

-- 2. v_transaction_depo_tf_widr
create or replace view v_transaction_depo_tf_widr as
select a.customer_id,
	count(t.transaction_type_id = 1) 'deposit',
    count(t.transaction_type_id = 2) 'transfer',
    count(t.transaction_type_id = 3) 'withdrawal'
from transactions t
join accounts a
where a.account_id = t.account_id
group by t.transaction_id;

select * from v_transaction_depo_tf_widr;

-- 3. vw_account_card_transaction_detail 
create or replace view vw_account_card_transaction_detail as
select a.account_id, a.account_number,
	a.account_type, a.balance,
	c.card_number, c.card_type,
	t.transaction_id, tt.name,
    t.amount
from transactions t
join accounts a
join cards c
join transaction_types tt
where a.account_id = t.account_id
and a.account_id = c.account_id
and t.transaction_type_id = tt.transaction_type_id;

select * from vw_account_card_transaction_detail;

-- 4. sp_get_transactions_report
drop procedure if exists sp_get_transactions_report; 
DELIMITER //
create procedure sp_get_transactions_report (
	in accid char(36)
    -- default 30 hari terakhir
)
begin
	select * from transactions
    where account_id = accid
    and transaction_date >= sysdate()-30;
end//
DELIMITER ;

select * from transactions;
call sp_get_transactions_report('802b2efe-e1d1-465b-940f-5cf573a2c985');
call sp_get_transactions_report('f75c87e7-70a8-4fbd-8ad6-9d5e9cefc314');
call sp_get_transactions_report('d29c5b3d-6bb3-4248-bf1a-4339bc80b6b0');

-- 5. fn_customer_loans_info 
-- ini menurutku lebih masuk prosedur dibanding fungsi.
-- karena dia mengembalikan records beberapa baris kolom, bukan 1 nilai
drop procedure if exists fn_customer_loans_info; 
DELIMITER //
create procedure fn_customer_loans_info (in cid char(36)) 
begin
	select loan_id, loan_amount,
		interest_rate, loan_terms_months,
        start_date, end_date, 
        status, (end_date-sysdate()) 'sisa hari'
    from loans
    where customer_id = cid;
end//
DELIMITER ;

select * from loans;
call fn_customer_loans_info('287bf982-89ce-44b5-bfdd-49407600309a');

-- 5. yang beneran 
drop function if exists fn_customer_loans_info; 
DELIMITER //
create function fn_customer_loans_info (cid char(36)) 
returns int
deterministic
begin
	declare amount int;
    
	set amount = (select end_date-sysdate()
					from loans
					where customer_id = cid);

    return amount;
end//
DELIMITER ;

select fn_customer_loans_info('287bf982-89ce-44b5-bfdd-49407600309a');
-- ini ga bisa, karna 1 cust bisa punya lebih dari 1 loans
-- saran: inputnya cid ganti jadi lid (loan_id), nanti pasti return 1 baris

-- 6. fn_cust_stats
-- ini juga prosedur kan... pas aku buat RETURN TABLE itu error...
drop procedure if exists fn_cust_stats; 
DELIMITER //
create procedure fn_cust_stats (in cid char(36)) 
begin
	select
		c.customer_id,
        count(a.customer_id) 'total akun',
        sum(a.balance) 'total balance',
        avg(a.balance) 'rata-rata balance'
    from customers c join accounts a
    where c.customer_id = cid
    and c.customer_id = a.customer_id
    group by c.customer_id;
end//
DELIMITER ;

call fn_cust_stats('287bf982-89ce-44b5-bfdd-49407600309a');

-- 6. yang beneran
drop function if exists fn_total_saldo; 
DELIMITER //
create function fn_total_saldo (cid char(36)) 
returns decimal(18,2)
deterministic
begin
	declare amount decimal(18,2);
    
	set amount = (select sum(balance)
					from accounts
					where customer_id = cid);

    return amount;
end//
DELIMITER ;

select fn_total_saldo('287bf982-89ce-44b5-bfdd-49407600309a');

-- 7. t_cegah_transaksi
drop trigger if exists t_cegah_transaksi; 
DELIMITER //
create trigger t_cegah_transaksi
before insert on transactions
for each row
begin
	declare waktu_terakhir date;
    
    select max(transaction_date) into waktu_terakhir
    from transactions;
    
	if new.transaction_date < waktu_terakhir then
		signal sqlstate '45000'
        set message_text = 'transaksi invalid';
    end if;
end//
DELIMITER ;

insert into transactions (account_id, transaction_type_id, amount)
values ('802b2efe-e1d1-465b-940f-5cf573a2c985', 2, 1000); 	-- berhasil

insert into transactions (account_id, transaction_type_id, amount, transaction_date)
values ('802b2efe-e1d1-465b-940f-5cf573a2c985', 2, 1000, date('1-1-1990', 'dd-mm-yyyy'));	-- tidak berhasil

-- 8. cr_potong_kredit
drop procedure if exists p_potong_kredit;
DELIMITER //
create procedure p_potong_kredit()
begin
	declare cek_kredit cursor for
		select balance
		from accounts
		where account_type = 'credit';

	open cek_kredit;
    
	read_loop: loop
		set balance = balance - balance*0.02;
	end loop;
	
    close cek_kredit;
end //
DELIMITER ;

call p_potong_kredit();