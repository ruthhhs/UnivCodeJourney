use bankdb;

-- no 1. index di tabel accounts
-- di kolom cutomer_id --> ceritanya nyari akun si cust tertentu

-- drop index cust on accounts;
-- ga bisa dihapus karna nempel di foreign key

create index cust on accounts(customer_id);

explain
select * from accounts where customer_id = '287bf982-89ce-44b5-bfdd-49407600309a' ;


-- no 2. index di tabel transactions
-- di kolom transaction_type_id --> nyari semua transaksi tipe tertentu

-- drop index tipe on transactions;
-- ga bisa dihapus karna nempel di foreign key

create index tipe on transactions(transaction_type_id);

explain
select * from transactions where transaction_type_id = 2 ;

-- no 3. index composite di tabel accounts
-- di kolom account_id dan customer_id

create index akun on accounts(account_id, customer_id);
explain
select * from accounts;