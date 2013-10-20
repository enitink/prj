create view vempbasic
as
select e.mgr,m.ename, count(m.empno) as NumofEmp from emp e, emp m 
where
e.mgr = m.empno group by e.mgr,m.ename order by 3 asc;