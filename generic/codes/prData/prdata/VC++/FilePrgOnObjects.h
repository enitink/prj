#ifndef FILEPRGONOBJECTS_H
#define FILEPRGONOBJECTS_H

#include"NString.h"

class Student
{
private :
	String Name;
	int Class;
	int RollNo;
	String Address;
	
public :
	Student();
	Student( String, int, int, String);
	
	void EnterData();
	void SetData( String, int, int, String );
	
	void DisplayData();
};

#endif
