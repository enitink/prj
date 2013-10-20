#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

typedef struct
{
	int Code;
	long unsigned int PhNumber;
}Phone;

class Person
{
private :
	char name[20];
	char address[40];
	Phone PhoneNumber;
public :
	Person()
	{
		strcpy( name , " ");
		strcpy( address , " ");
		PhoneNumber.Code = 0;
		PhoneNumber.PhNumber = 0;
	}
	
	Person( char name[], char address[], Phone PhoneNumber )
	{
		SetData( name, address, PhoneNumber );
	}
	
	void SetData(char name[], char address[], Phone PhoneNumber )
	{
		strcpy( this->name, name);
		strcpy( this->address, address);
		this->PhoneNumber.Code = PhoneNumber.Code;
		this->PhoneNumber.PhNumber = PhoneNumber.PhNumber;
	}
	
	void DisplayData()
	{
		cout << "Name         : " << name;
		cout << "Address      : " << address;
		cout << "Phone Number : " << PhoneNumber.Code << "-" << PhoneNumber.PhNumber;
	}
};

int main()
{
	Person ob;
	ofstream OutFile("abc.dat");
	char name[20];
	char address[40];
	Phone PhoneNumber;
	
	do
	{
		cout << "Enter Name           : ";
		cin >> name;
		cout << "Enter Address        : ";
		cin >> address;
		cout << "Enter Phone City Code: ";
		cin >> PhoneNumber.Code;
		cout << "Enter Phone Number   : ";
		cin >> PhoneNumber.PhNumber;
		
		ob.SetData( name, address, PhoneNumber);
		OutFile.write( (char *) &ob, sizeof(Person));
	}while(PhoneNumber.Code != 0);
	
	OutFile.close();
	ifstream InFile("abc.dat");
	
	InFile.read( (char *) &ob, sizeof(Person));
	ob.DisplayData();
	cout << endl;
	return 0;
}