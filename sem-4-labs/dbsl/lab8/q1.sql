set serveroutput on
declare
    rno StudentTable.RollNo%TYPE;
    g StudentTable.GPA%TYPE;
begin
    rno := '&rno';
    select gpa into G from StudentTable where RollNo = rno;
    dbms_output.put_line('GPA: ' || g);
end;
/