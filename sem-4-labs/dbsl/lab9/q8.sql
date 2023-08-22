set serveroutput on;
declare
    cursor c is select * from instructor where dept_name = 'Biology' FOR update;
    reqBudget number;
    maxBudget number;
begin
    select budget into maxBudget from Department where dept_name = 'Biology';
    commit;
    reqBudget := 0;
    for i in C
    loop
        reqBudget := reqBudget + I.salary * 1.2;
        update instructor set salary = salary * 1.2 where current of c;
    end loop;
    if reqBudget > maxBudget then
        dbms_output.put_line('oops');
        rollback;
    else
        dbms_output.put_line('salaries went up');
    end if;
end;
/