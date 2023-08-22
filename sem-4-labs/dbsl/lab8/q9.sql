set serveroutput on
declare
    outOfRange exception;
    g StudentTable.GPA%TYPE;
    i number;
    n number;
begin
    select count(*) into n from StudentTable;
    i := 1;
    while i <= n
    loop
        select gpa into g from StudentTable where RollNo = i;
        if g < 0 and g > 10 then
            raise outOfRange;
        end if;
        i := i + 1;
    end loop;
exception 
    when outOfRange then
        dbms_output.put_line('gpa out of range');
end;
/