create table Old_Data_Instructor(
    id varchar(5),
    name varchar(20),
    dept_name varchar(20),
    salary numeric(8,2),
    primary key (ID));

create or replace trigger inst_sal
before update of salary on instructor
for each row
begin
    insert into Old_Data_Instructor values(:OLD.ID, :OLD.name, :OLD.dept_name, :OLD.salary);
end;
/