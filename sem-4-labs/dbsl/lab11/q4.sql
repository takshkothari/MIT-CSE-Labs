create table Client_master (
    client_no number,
    name varchar(20),
    address varchar(50),
    bal_due number,
    primary key (client_no));

create table auditclient (
    client_no number,
    name varchar(20),
    bal_due number,
    operation varchar(20),
    userid number,
    opdate date);

create or replace trigger client_trigger
before update or delete on Client_master
for each row
begin
    case
    when updating then
        insert into auditClient values(:OLD.client_no, :OLD.name, :OLD.bal_due, 'Update', 6969, sysdate);
    when deleting then
        insert into auditClient values(:OLD.client_no, :OLD.name, :OLD.bal_due, 'Delete', 6969, sysdate);
    end case;
end;
/