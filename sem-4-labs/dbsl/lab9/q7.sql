set serveroutput on
declare
    cursor C1 is select * from advisor;
    cursor C2(i takes.ID%TYPE) is select * from takes where ID = i;
    cursor C3(i teaches.ID%TYPE) is select * from teaches where ID = i;
    stdName student.name%TYPE;
    flag numeric(1);
begin
    for i in c1
    loop
        flag := 0;
        for j in c2(i.s_id)
        loop
            for z in c3(i.i_id)
            loop
                if j.course_id = z.course_id and j.sec_id = z.sec_id and j.semester = z.semester and j.year = z.year then
                select name into stdName from student where id = j.id;
                dbms_output.put_line('ID: ' || j.id || 'Name: ' || stdName);
                flag := 1;
                end if;
            end loop;
            if flag = 1 then exit; 
            end if;
        end loop;
    end loop;
end;
/