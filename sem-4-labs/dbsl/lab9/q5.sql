update StudentTable set LetterGrade = 'F';

set serveroutput on
declare
    cursor c is select * from StudentTable for update;
    g StudentTable.GPA%TYPE;
begin
    for i in c
    loop
        g := i.gpa;
        if g > 0 and g <= 4 then
            update StudentTable set LetterGrade = 'F' where current of c;
        elsif g > 4 and g <= 5 then
            update StudentTable set LetterGrade = 'E' where current of c;
        elsif g > 5 and g <= 6 then
            update StudentTable set LetterGrade = 'D' where current of c;
        elsif g > 6 and g <= 7 then
            update StudentTable set LetterGrade = 'C' where current of c;
        elsif g > 7 and g <= 8 then
            update StudentTable set LetterGrade = 'B' where current of c;
        elsif g > 8 and g <= 9 then
            update StudentTable set LetterGrade = 'A' where current of c;
        elsif g > 9 and g <= 10 then
            update StudentTable set LetterGrade = 'A+' where current of c;
        end if;
    end loop;
end;
/