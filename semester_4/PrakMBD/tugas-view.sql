-- ===== TUGAS PO 1 =====
-- Nama	: Ruth Septriana Sipangkar
-- NIM	: 24060124120024
-- Lab	: MBD C2

use bankdb;

-- a. view semua costumer
CREATE VIEW v_customer_all AS
SELECT * FROM customers;

SELECT * FROM v_customer_all;

select * from transaction_types;

-- b. view transaksi deposit
create view v_deposit_transaction as
select * from transactions 
where transaction_type_id = 1;

select * from v_deposit_transaction;

-- c. view transaksi transfer
create view v_transfer_transaction as
select * from transactions 
where transaction_type_id = 2;

select * from v_transfer_transaction;