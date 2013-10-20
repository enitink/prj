create or replace trigger Ins_and_Upd
before insert or update of sal on emp
for each row

begin
	if Inserting then
		Insert into emp 
		(ename, empno, job, mgr, hiredate, sal, comm,deptno)
		values
		(:new.ename, :new.empno, :new.job, :new.mgr, :new.hiredate, :new.sal, :new.comm, :new.deptno);
	else
		Insert into emp 
		(ename, empno, job, mgr, hiredate, sal, comm,deptno)
		values
		(:old.ename, :old.empno, :old.job, :old.mgr, :old.hiredate, :new.sal, :old.comm, :old.deptno);
	end if;

end;
/