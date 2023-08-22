set serveroutput on
declare
    cursor c is select * from takes where course_id = 'CS-101';
    cr student.tot_cred%TYPE;
begin
    for i in c
    loop
        select tot_cred into cr from student where id = i.id;
        if cr < 40 then
            delete from takes where id = i.id and course_id = i.course_id;
        end if;
    end loop;
end;
/