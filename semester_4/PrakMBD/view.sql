use bankdb;

-- penciptaan view
CREATE VIEW v_customer_all AS
SELECT customer_id, first_name, last_name, email
FROM customers;

-- pemangggilan view
SELECT * FROM v_customer_all;
select first_name from v_customer_all;

SELECT *
FROM v_customer_all
WHERE first_name = 'Swen';

-- pengaplikasian view
SELECT email FROM v_customer_all;

-- tanpa view
SELECT email FROM customers;

-- pengubahan view
ALTER VIEW v_customer_all AS
SELECT first_name, email
FROM customers;

SELECT * FROM v_customer_all;

CREATE OR REPLACE VIEW v_customer_all AS
SELECT first_name, last_name, email
FROM customers;

-- penggantian nama view
RENAME TABLE v_customer_all TO v_customer_basic;
SELECT * FROM v_customer_basic;

-- menggunakan drop
DROP VIEW v_customer_basic;

CREATE VIEW v_customer_baru AS
SELECT first_name, last_name, email
FROM customers;

SELECT * FROM v_customer_baru;


-- ===== TUGAS PO 1 =====

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