use bankdb;

select * from accounts;
drop procedure get_saldo;
drop procedure get_saldo2;

DELIMITER //
create procedure get_saldo(
	in x char(10)
    )
begin
	select balance
    from accounts
    where account_number = x;
end//
DELIMITER ;

call get_saldo('8346813622');

DELIMITER //
create procedure get_saldo2(
	in x char(10),
    out y DOUBLE(8,2)
    )
begin
	select balance into y
    from accounts
    where account_number = x;
end//
DELIMITER ;

call get_saldo2('8346813622', @output);
select @output;