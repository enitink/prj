#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

class Employee
{
private :
	int code;
	int salary;
public :
	Employee()
	{
		code = 0;
		salary = 0;
	}
	void SetData(int code, int salary)
	{ 
		this->code = code;
		this->salary = salary;
	}
	void Display()
	{
		cout << endl << "Code   : " << code;
		cout << endl << "Salary : " << salary;
	}
};

int main()
{
	Employee ob,ob1;

	int code, salary;
	
	cout << endl << "\t\tEnter Data for OB : ";
	cout << endl << "Enter Code : ";
	cin  >> code;
	cout << "Enter Salary : ";
	cin  >> salary;

	ob.SetData(code,salary);
	
	cout << endl << "\t\tEnter Data for OB1: ";
	cout << endl << "Enter Code   : ";
        cin  >> code;
	cout << "Enter Salary : ";
        cin >> salary;
	
	ob1.SetData(code,salary);
	
	cout << endl <<  "\t\tData of OB : ";
	ob.Display();
	
	cout << endl <<  "\t\tData of OB1 : ";
	ob1.Display();
	
	cout << endl;
	return 0;
}
