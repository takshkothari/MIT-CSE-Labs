set serveroutput on
declare
    i numeric(1);
    g StudentTable.GPA%TYPE;
begin
    i := 1;
    loop
        select gpa into g from StudentTable where RollNo = i;
        if g > 0 and g <= 4 then
            dbms_output.put_line('grade f');
        elsif g > 4 and g <= 5 then
            dbms_output.put_line('grade e');
       elsif g > 5 and g <= 6 then
            dbms_output.put_line('grade d');
        elsif g > 6 and g <= 7 then
            dbms_output.put_line('grade c');
        elsif g > 7 and g <= 8 then
            dbms_output.put_line('grade b');
        elsif g > 8 and g <= 9 then
            dbms_output.put_line('grade a');
        elsif g > 9 and g <= 10 then
            dbms_output.put_line('grade a+');
        else
            dbms_output.put_line('no grade');
        end if;
        i := i + 1;
        if i > 5 then exit;
        end if;
    end loop;
end;
/