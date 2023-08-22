set serveroutput on
declare
    di date;
    dr date;
    n numeric(3);
    f numeric(3);
begin
    di := to_date('&issuedate', 'dd-mm-yy');
    dr := to_date('&returndate', 'dd-mm-yy');
    n := dr - di;
    if n <= 7 then
        f := 0;
    elsif n <= 15 then
        f := n;
    elsif n <= 30 then
        f := n * 2;
    else
        f := n * 5;
    end if;
    dbms_output.put_line('fine is '|| f);
end;
/