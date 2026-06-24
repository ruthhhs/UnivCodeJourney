-- ===== TUGAS PO 2 =====
-- Nama	: Ruth Septriana Sipangkar
-- NIM	: 24060124120024
-- Lab	: MBD C2

use bankdb;

-- 1. fn_GetCustomerAccountCount
drop function if exists fn_GetCustomerAccountCount;

DELIMITER //
create function fn_GetCustomerAccountCount (cid char(36))
returns int
deterministic
begin
	declare amount int;
    
	set amount = (select count(*) from accounts where customer_id = cid);

    return amount;
end//
DELIMITER ;

select fn_GetCustomerAccountCount ('23fd617f-9912-4a67-b5cb-60147b25930c') as 'count_account';

-- 2. fn_GetTotalBalanceByCustomer
drop function if exists fn_GetTotalBalanceByCustomer;

DELIMITER //
create function fn_GetTotalBalanceByCustomer (cid char(36))
returns decimal(18,2)
deterministic
begin
	declare amount decimal(18,2);
    
	set amount = (select coalesce(sum(balance), 0) from accounts where customer_id = cid);

    return amount;
end//
DELIMITER ;

select fn_GetTotalBalanceByCustomer ('e8a917b4-9641-4271-91a2-2a0ef3477c76') as 'total_balance';

-- 3. fn_GetActiveLoanCount
drop function if exists fn_GetActiveLoanCount;

DELIMITER //
create function fn_GetActiveLoanCount (cid char(36))
returns decimal(18,2)
deterministic
begin
	declare amount decimal(18,2);
    
	set amount = (select count(*) from loans where customer_id = cid and status = 'active');

    return amount;
end//
DELIMITER ;

select fn_GetActiveLoanCount ('e8a917b4-9641-4271-91a2-2a0ef3477c76') as 'count_loan';