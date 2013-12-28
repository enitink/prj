declare 
X integer := 20;
Y integer := 50;
Z integer;

begin
dbms_output.put_line('Welcome to PL SQL Program');

Z := X + Y;

dbms_output.put_line('Sum of ' || X || ' and ' || y || ' is ' || Z);

end;
     /