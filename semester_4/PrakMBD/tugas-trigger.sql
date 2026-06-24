-- ===== TUGAS PO 2 =====
-- Nama	: Ruth Septriana Sipangkar
-- NIM	: 24060124120024
-- Lab	: MBD C2

use bankdb;

-- 1. tr_CheckBalance_BeforeTransaction
drop trigger if exists tr_CheckBalance_BeforeTransaction;

DELIMITER $$
create trigger tr_CheckBalance_BeforeTransaction
before insert on transactions
for each row
begin
	declare current_balance decimal(18,2);

    select balance
    into current_balance
    from accounts
    where account_id = new.account_id;

    if new.transaction_type_id = 2 or new.transaction_type_id = 3 then
        if current_balance < new.amount then
            SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Saldo akun tidak mencukupi untuk transaksi';
        end if;
    end if;
end$$
DELIMITER ;

insert into transactions (account_id, transaction_type_id, amount)
values ('802b2efe-e1d1-465b-940f-5cf573a2c985', 2, 1000); -- saldo mencukupi

insert into transactions (account_id, transaction_type_id, amount)
values ('802b2efe-e1d1-465b-940f-5cf573a2c985', 2, 500000); -- saldo tidak mencukupi

-- 2. tr_CheckMinimumLoanAmount_BeforeInsert
drop trigger if exists tr_CheckMinimumLoanAmount_BeforeInsert;

DELIMITER $$
create trigger tr_CheckMinimumLoanAmount_BeforeInsert
before insert on loans
for each row
begin
    if new.loan_amount < 100.0 then
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'Jumlah pinjaman minimal 100.0';
    end if;
end$$
DELIMITER ;

select * from loans;

insert into loans (customer_id, loan_amount, status)
values ('287bf982-89ce-44b5-bfdd-49407600309a', 100, 'active'); -- minimal pinjaman mencukupi

insert into loans (customer_id, loan_amount, status)
values ('287bf982-89ce-44b5-bfdd-49407600309a', 50, 'active'); -- minimal pinjaman tidak mencukupi

-- 3. tr_LimitAccountsPerCustomer
drop trigger if exists tr_LimitAccountsPerCustomer;

DELIMITER $$
create trigger tr_LimitAccountsPerCustomer
before insert on accounts
for each row
begin
	declare amount int;
	set amount = (select count(*) from accounts where customer_id = new.customer_id);
    
    if amount >= 3 then
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'Sudah terdapat 3 akun dengan customer_id ini, tidak bisa menambah akun';
    end if;
end$$
DELIMITER ;

insert into accounts (customer_id, account_number, account_type, balance)
values ('24aa2ce2-4b8b-11f1-b1c2-eff5fc1160ad', 1001, 'savings', 500); -- akun ke 4, sudah tidak boleh

insert into accounts (customer_id, account_number, account_type, balance)
values ('287bf982-89ce-44b5-bfdd-49407600309a', 1002, 'credit', 500); -- akun ke 3, masih bisa
