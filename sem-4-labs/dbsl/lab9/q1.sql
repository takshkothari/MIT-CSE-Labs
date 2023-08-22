create table salary_raise(
    instructor_id number,
    raise_date date,
    raise_amt number);

set serveroutput on
declare
    cursor c(dname instructor.dept_name%TYPE) is select * from instructor where dept_name = dname;
    str instructor.dept_name%TYPE;
    inst instructor%ROWTYPE;
begin
    str := '&DeptName';
    open c(str);
    loop
        fetch c into inst;
        exit when c%NOTFOUND;
        update instructor set salary = salary * 1.05 where id = inst.id;
        insert into salary_raise values(inst.id, SYSDATE, inst.salary * 0.05);
    end loop;
    close c;
end;
/