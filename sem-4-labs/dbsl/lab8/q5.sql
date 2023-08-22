alter table StudentTable add (LetterGrade varchar(2));

set serveroutput on
declare
    g StudentTable.GPA%TYPE;
    i number;
    n number;
begin
    select count(*) into n from StudentTable;
    i := 1;
    while i <= n
    loop
        select gpa into g from StudentTable where RollNo = i;
        if g > 0 and g <= 4 then
            update StudentTable set LetterGrade = 'F' where RollNo = i;
        elsif g > 4 and g <= 5 then
            update StudentTable set LetterGrade = 'E' where RollNo = i;
       elsif g > 5 and g <= 6 then
            update StudentTable set LetterGrade = 'D' where RollNo = i;
        elsif g > 6 and g <= 7 then
            update StudentTable set LetterGrade = 'C' where RollNo = i;
        elsif g > 7 and g <= 8 then
            update StudentTable set LetterGrade = 'B' where RollNo = i;
        elsif g > 8 and g <= 9 then
            update StudentTable set LetterGrade = 'A' where RollNo = i;
        elsif g > 9 and g <= 10 then
            update StudentTable set LetterGrade = 'A+' where RollNo = i;
        end if;
        i := i + 1;
    end loop;
end;
/
