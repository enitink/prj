#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<string.h>

#include<vector>

using std :: vector;

class Student
{
protected :
	int roll;
	char *name;
public :
	Student()
	{
		roll = 0;
		name = new char[30];
	}
	Student(int roll, char *name)
	{
		int ln = strlen(name);
		this->name = new char[ln + 1];
				
		SetData(roll, name);
	}
	virtual ~Student()
	{
		delete [] name;
	}
	virtual void SetData(int roll, char *name)
	{
		this->roll = roll;
		strcpy(this->name, name);
	}
	virtual void ShowData()
	{
		cout << endl << "\tRoll of the Student   : " << roll;
		cout << endl << "\tName of the Student   : " << name;
	} 
};

class NoofVirtual : public Student
{
	friend void Showlist(NoofVirtual &);
private :
	int count;	
public :
	NoofVirtual()
	{
		count = 0;
	}
	NoofVirtual(int roll, char *name, int count) : Student(roll, name)
	{
		this->count = count;
	}
	~NoofVirtual()
	{}		
	virtual void SetData(int roll, char *name, int count)
	{
		this->count = count;
		Student :: SetData(roll, name);
	}
	virtual void ShowData()
	{
		cout << endl << "\tRoll No. of the Student      : " << roll;
		cout << endl << "\tName of the Student          : " << name; 
		cout << endl << "\tNo. of Virtual Fuctions Used : " << count;
	}
};

void Showlist(NoofVirtual &ob)
{
	if(ob.count >= 10)
	{
		ob.ShowData();
	}	
}

int main()
{
	NoofVirtual ob[10];
	vector <Student *> ptr[10];
	int roll,count,i;
	char *name;
	
	name = new char[30];
	
	for(i = 0; i < 10; ++i)
		ptr[i] = &ob[i];
		
	for(i = 0; i < 10; ++i)
	{
		cout << endl << "Enter data for ob[" << i  << "] : ";
		cout << endl << "\tEnter Roll : "; 
		cin >> roll;
		cout << "\tEnter Name : ";
		cin >> name;
		cout << "\tEnter No. of Virtual fuctions used : ";
		cin >> count;
		ptr[i]->SetData(roll,name,count);
	}
	
	for(i = 0; i < 10; ++i)
		Showlist(ob[i]);
	
	cout << endl;
	return 0;
}
