set serveroutput on
declare
    i numeric(1);
    g StudentTable.GPA%TYPE;
    gr varchar(2);
begin
    i := 1;
    loop
        select gpa into g from StudentTable where RollNo = i;
        if g > 0 and g <= 4 then
            gr :='F';
            goto disp;
        elsif g > 4 and g <= 5 then
            gr :='E';
            goto disp;
       elsif g > 5 and g <= 6 then
            gr :='D';
            goto disp;
        elsif g > 6 and g <= 7 then
            gr :='C';
            goto disp;
        elsif g > 7 and g <= 8 then
            gr :='B';
            goto disp;
        elsif g > 8 and g <= 9 then
            gr :='A';
            goto disp;
        elsif g > 9 and g <= 10 then
            gr :='A+';
            goto disp;
        else
            dbms_output.put_line('no grade');
        end if;
        <<disp>>
            dbms_output.put_line('grade is '|| gr);
        i := i + 1;
        if i > 5 then exit;
        end if;
    end loop;
end;
/
