set serveroutput on
declare
    g StudentTable.GPA%TYPE;
    mg StudentTable.GPA%TYPE;
    i number;
    n number;
begin
    select count(*) into n from StudentTable;
    i := 1;
    mg := 0;
    for i in 1..n loop
        select gpa into g from StudentTable where RollNo = i;
        if g > mg then
            mg := g;
        end if;
    end loop;
    select RollNo into i from StudentTable where gpa = mg;
    dbms_output.put_line('student with max gpa is roll no. '|| i);
end;
/
