declare


cursor C is
select e.ename, e.sal from emp e, dept d where
e.deptno = d.deptno and d.dname = 'ACCOUNTING' order by e.sal desc;

rec C%rowtype;

begin

open C;
fetch C into rec;
loop
	fetch C into rec;
	dbms_output.put_line(rec.ename || '     ' || rec.sal);
	exit when C%NotFound;
end loop;

end;
/