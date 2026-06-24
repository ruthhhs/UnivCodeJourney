use bankdb;

-- 1.
DELIMITER //
create function fn_GetCostumerTotalLoan (cid char(36))
returns decimal(18,2)
deterministic
begin
	declare amount decimal(18,2);
    
	set amount = (select coalesce(sum(loan_amount), 0) from loans where customer_id = cid and status = 'active');

    return amount;
end//
DELIMITER ;

drop function if exists fn_GetCostumerTotalLoan;
select fn_GetCostumerTotalLoan ('e8a917b4-9641-4271-91a2-2a0ef3477c76') as 'total_loan';

-- 2.
DELIMITER //
create function fn_GetTransactionCountByAccount (aid char(36))
returns int
deterministic
begin
	declare amount int;
    
	set amount = (select count(*) from transactions where account_id = aid);

    return amount;
end//
DELIMITER ;

drop function if exists fn_GetTransactionCountByAccount;
select fn_GetTransactionCountByAccount ('802b2efe-e1d1-465b-940f-5cf573a2c985') as 'total_transaction';
select fn_GetTransactionCountByAccount ('f75c87e7-70a8-4fbd-8ad6-9d5e9cefc314') as 'total_transaction';

-- 3.
DELIMITER //
create function fn_GetAccountTypeByNumber (anum char(10))
returns varchar(50)
deterministic
begin
	declare amount varchar(50);
    
	set amount = (select account_type from accounts where account_number = anum);

    return amount;
end//
DELIMITER ;

drop function if exists fn_GetAccountTypeByNumber;
select fn_GetAccountTypeByNumber ('8346813622') as 'account_type';