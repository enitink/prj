#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	char name[30];
	int age;
	char address[40];
public :
	Person()
	{
		name = " ";
		age = 0;
		address = " ";
	}
	Person(char name[], int age, char address[])
	{
		SetData( name, age, address[]);
	}
	void SetData(char name[], int age, char address[])
	{
		strcpy(this->name, name);
		strcpy(this->address, address);
		this->age = age;
	}
	friend void DisplayData(Person);
	
};

void DisplayData(Person x)
{
		cout << "Name    : " << x.name;
		cout << "Age     : " << x.age;
		cout << "Address : " << x.address;
}

class Student : Public Person
{
private :
	int cl;
	char sec;
public :
	Student()
	{
		cl = 0;
		sec = " ";
	}
	
	Student(char name[], int age, char address[], int cl, char sec) : 
	Person( name, age, address[])
	{
		SetData( name, age, address[], cl, sec, age, sec);
	}
	
	void SetData(char name[], int age, char address[], int cl, char sec)
	{
		Person :: SetData( name, age, address[]);
		this->age = age;
		this->sec = sec;
	}
	
	void DisplayData()
	{
		DisplayData(
};
 
