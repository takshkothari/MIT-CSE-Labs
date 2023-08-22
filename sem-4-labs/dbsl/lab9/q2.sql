declare
    cursor c is select * from(select * from student order by tot_cred) where rownum < 11;
begin
    for i in c
    loop
        dbms_output.put_line('ID: ' || i.id || ' Name: ' || i.name || ' Dept_name: ' || i.dept_name || ' Total credits: ' || i.tot_cred);
    end loop;
end;
/