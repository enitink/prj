#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

class Student
{
private :
	int roll;
	int marks;
public :
	Student()
	{
		roll = 0;
		marks = 0;
	}
	Student(int roll, int marks)
	{
		this->roll = roll;
		this->marks = marks;
	}
	void Input(int roll, int marks)
	{
		this->roll = roll;
		this->marks = marks;
	}
	void Display()
	{
		cout << endl << "\t\tROLL    : " << roll;
		cout << endl << "\t\tMARKS   : " << marks;
		cout << endl << "\t\t\tREMARKS : ";
		if(marks < 30)
			cout << "FAIL";
		else
			cout << "PASS";
	}
};

int main()
{
	Student ob,ob1,ob2;
	int roll, marks;	

	cout << endl << "enter data for ob : " << endl << "\tenter roll  :";
	cin >> roll;
	cout << "\tenter marks :";
	cin >> marks;
	ob.Input(roll,marks);
	cout << endl << "enter data for ob1 : " << endl << "\tenter roll  :";
	cin >> roll;
	cout << "\tenter marks :";
	cin >> marks;
	ob1.Input(roll, marks);
	cout << endl << "enter data for ob2 : " << endl << "\tenter roll  :";
	cin >> roll;
	cout << "\tenter marks :";
	cin >> marks;
	ob2.Input(roll, marks);
	
	cout << endl << "Ob";
	ob.Display();
	cout << endl << "Ob1";
	ob1.Display();
	cout << endl << "Ob2";
	ob2.Display();
	cout << endl;
	
	return 0;
}
