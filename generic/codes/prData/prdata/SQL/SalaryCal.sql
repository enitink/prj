create or replace function SalCal(Salary emp.sal%type)
return emp.sal%type
is
	resal emp.sal%type;
	rGrade integer := 0;
					
begin
	select grade into rGrade from salgrade where salary between losal and hisal;

	if(rGrade = 1) then
		resal := Salary * (3.87);
	else 
		if(rGrade = 2) then
			resal := Salary * (3.5);
		else
			if(rGrade = 3) then
				resal := Salary * (2.72);
			else
				if(rGrade = 4) then
					resal := Salary * (2.68);
				else
					if(rGrade = 5) then
						resal := Salary * (2);
					end if;
				end if;
			end if;			
		end if;	
	end if;
	
	return resal;
end;
/