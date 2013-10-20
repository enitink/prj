create or replace package MyPack
as
	function SalCal(Salary emp.sal%type) return emp.sal%type;
	procedure Print;
	
end MyPack;
/