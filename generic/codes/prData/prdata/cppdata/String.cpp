#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include "NString.h"

class Name
{
private :
	String nm;
public :
	Name()
	{
		nm = "  ";
	}
	Name(String nam)
	{
		nm = nam;
	}	
	void EnterName()
	{
		cout << endl <<  "Enter Name  : ";
		cin >> nm;
	}	
	void DisplayData()
	{
		cout << endl << "Name : " << nm;
	}
};

int main()
{
	String ob(20);
	String ob1;
	String ob2("My Name is Nitin");
	
	Name student(ob2);
	
	cout << "Enter any String : ";
	cin >> ob;

	cout << "Enter Second String : ";
	cin >> ob1;
	
	cout << endl << "String ob is : " << DouValue(ob);
	cout << endl << "String ob1 is : " << IntValue(ob1) << endl;
	
	student.DisplayData();
	student.EnterName();
	student.DisplayData();
	
	cout << endl;
	
	return 0;
}

