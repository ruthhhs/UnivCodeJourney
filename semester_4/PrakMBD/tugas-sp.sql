-- ===== TUGAS PO 1 =====
-- Nama	: Ruth Septriana Sipangkar
-- NIM	: 24060124120024
-- Lab	: MBD C2

use bankdb;

-- a. Procedure sp_CreateCustomer
-- untuk menambahkan customer baru ke dalam tabel customers
-- input: first_name, last_name, email, phone_number, address
DELIMITER //
create procedure sp_CreateCustomer(
	in fname varchar(50),
    in lname varchar(50),
    in eml varchar(50),
    in pnum varchar(20),
    in adr varchar(225)
    )
begin
	insert into customers(customer_id, first_name, last_name, email, phone_number, address, created_at)
    values (UUID(), fname, lname, eml, pnum, adr, CURRENT_TIMESTAMP);
end//
DELIMITER ;

drop procedure sp_CreateCustomer;
call sp_CreateCustomer('Koushi', 'Sugawara', 'kousuga@gmail.com', '123-456', 'idk');
select * from customers where first_name = 'Koushi';

-- b. Procedure sp_CreateAccount
-- untuk membuat akun baru untuk customer yang sudah ada
-- input: customer_id, account_number, account_type, balance
-- Catatan: Tambahkan validasi untuk memastikan bahwa customer_id benar-benar ada pada tabel customers
DELIMITER //
create procedure sp_CreateAccount(
	in cid char(36),
    in anum char(20),
    in atype varchar(50),
    in blc decimal(18,2)
    )
begin
	if exists (
        select 1 from customers
        where customer_id = cid
    ) then
		insert into accounts(account_id, customer_id, account_number, account_type, balance, created_at)
		values (UUID(), cid, anum, atype, blc, CURRENT_TIMESTAMP);
	else
		signal sqlstate'45000'
		set message_text = 'Customer tidak ada';
	end if;
end//
DELIMITER ;

drop procedure sp_CreateAccount;
call sp_CreateAccount('24aa2ce2', '2104', 'savings', 217000000); -- ga bisa
call sp_CreateAccount('24aa2ce2-4b8b-11f1-b1c2-eff5fc1160ad', '2104', 'savings', 217000000); -- bisa
select * from accounts where customer_id = '24aa2ce2-4b8b-11f1-b1c2-eff5fc1160ad';

-- c. Procedure sp_MakeTransaction
-- untuk menambahkan transaksi baru
-- input: account_id, transaction_type_id, amount, description, reference_account (opsional)
-- Catatan: Tambahkan validasi untuk transfer, jika jumlah transfer melebihi balance maka transaksi dihentikan
DELIMITER //
create procedure sp_MakeTransaction(
	in aid char(36),
    in ttypeid int(11),
    in amt decimal(18,2),
    in descr varchar(50)
    )
begin
	if exists (
        select 1 from accounts
        where account_id = aid and balance >= amt
    ) then
		insert into transactions(transaction_id, account_id, transaction_type_id, amount,
									transaction_date, description, reference_account)
		values (UUID(), aid, ttypeid, amount, CURRENT_TIMESTAMP, descr, null);
	else
		signal sqlstate'45000'
		set message_text = 'Account tidak ada atau saldo tidak mencukupi';
	end if;
end//
DELIMITER ;

drop procedure sp_MakeTransaction;
call sp_MakeTransaction('dd89894b-4b8c-11f1-b1c2-eff5fc1160ad', 2, 300000000, 'tf gagal (kelebihan dari balance');
call sp_MakeTransaction('dd89894b-4b8c-11f1-b1c2-eff5fc1160ad', 2, 30, 'tf berhasil (tida melebihi balance');
select * from transactions where account_id = 'dd89894b-4b8c-11f1-b1c2-eff5fc1160ad';

-- d. Procedure sp_GetCustomerSummary
-- untuk menampilkan ringkasan data customer berdasarkan customer_id
-- meliputi: Nama lengkap customer, Jumlah akun yang dimiliki,
-- Jumlah total saldo semua akun, Jumlah pinjaman aktif, Total pinjaman amount aktif.
DELIMITER //
create procedure sp_GetCustomerSummary(
	in cid char(36)
)
begin
	select
		concat(c.first_name, ' ', c.last_name) as namaLengkap,
		(
			select count(*) from accounts a 
			where a.customer_id = c.customer_id
		) as jumlahAkun,
        (
			select coalesce(sum(a.balance), 0) from accounts a
			where a.customer_id = c.customer_id
		) as totalSaldo,
        (
			select count(*) from loans l
			where l.customer_id = c.customer_id 
            and l.status = 'active'
        ) as jumlahPinjaman,
        (
			select coalesce(sum(l.loan_amount), 0) from loans l
			where l.customer_id = c.customer_id
            and l.status = 'active'
        ) as totalPinjaman
	from customers c where c.customer_id = cid;
end//
DELIMITER ;

drop procedure sp_GetCustomerSummary;
call sp_GetCustomerSummary('24aa2ce2-4b8b-11f1-b1c2-eff5fc1160ad');

select * from loans;
call sp_GetCustomerSummary('e8a917b4-9641-4271-91a2-2a0ef3477c76');