create view Advisor_Student as 
select advisor.s_id, advisor.i_id, student.name s_name, instructor.name i_name
from advisor, student, instructor where advisor.s_id = student.id and advisor.i_id = instructor.id;

create or replace trigger delAdvisor
instead of delete on Advisor_Student
for each row
begin 
    delete from advisor where s_id = :OLD.s_id and i_id = :OLD.i_id;
end;
/