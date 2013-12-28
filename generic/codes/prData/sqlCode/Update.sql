Declare

begin

	for x in (select distinct mgr from emp) loop
		dbms_output.put_line('abc');
		update emp set sal = 1.2 * sal where empno = x.mgr;
	end loop;
	
	for y in (select empno from emp where empno not in (select distinct mgr from emp)) loop
		update emp set sal = sal * 1.4	where empno = y.empno;
	end loop;
end;
/