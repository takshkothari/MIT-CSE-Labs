create table log_change_Takes(
    Time_Of_Change date,
    id varchar(5),
    course_id varchar(8),
    sec_id varchar(8),
    semester varchar(6),
    year numeric(4,0),
    grade varchar(2),
    primary key (ID, course_id, sec_id, semester, year));

set serveroutput on

create or replace trigger alt_takes_trigger
before insert or update or delete on takes
for each row
begin
    case
    when inserting then
        insert into log_change_Takes
        values(current_date,:NEW.ID, :NEW.course_id, :NEW.sec_id, :NEW.semester, :NEW.year, :NEW.grade);
    when updating or deleting then
        insert into log_change_Takes
        values(current_date,:OLD.ID, :OLD.course_id, :OLD.sec_id, :OLD.semester, :OLD.year, :OLD.grade);
    end case;
end;
/