#include"FilePrgOnObjects.h"
#include"NString.h"

using std :: cout;
using std :: cin;
using std :: endl;

Student :: Student()
{
	Class = 0;
	RollNo = 0;
}

Student :: Student(String Name, int Class, int RollNo, String Address)
{
	SetData(Name, Class, RollNo, Address);
}

void Student :: SetData(String Name, int Class, int RollNo, String Address)
{
	this->Name = Name;
	this->Class = Class;
	this->RollNo = RollNo;
	this->Address = Address;
}

void Student :: EnterData()
{
	cout << endl << "Enter Following Details For The Students : ";
	cout << endl << "\t\tName    : ";
	cin >> Name;
	cout << "\t\tClass   : ";
	cin >> Class;
	cout << "\t\tRollNo  : ";
	cin >> RollNo;
	cout << "\t\tAddress : ";
	cin >> Address;
}

void Student :: DisplayData()
{
	cout << endl << "Following Details For The Students were Entered : ";
	cout << endl << "\t\tName    : " << Name;
	cout << endl << "\t\tClass   : " <<  Class;
	cout << endl << "\t\tRollNo  : " << RollNo;
	cout << endl << "\t\tAddress : " <<  Address;
}
