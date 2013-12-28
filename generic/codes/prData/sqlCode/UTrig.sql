create or replace trigger tempsal 
before update of sal on emp
for each row

begin
	if :new.sal <= :old.sal then
		raise_application_error(-20395, 'Value less error');
	end if;

end;
/