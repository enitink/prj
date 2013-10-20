#include<iostream>
#include"Date1.h"

using std :: cout;
using std :: endl;

void PerformTask()
{
	Date DOb1;
	Date DOb2(12, 01, 2001);
	Date DOb3(13, 01, 2001);
	Date DOb4(02,29, 2001);

	cout << endl << "Date of DOb1 : ";	
	DOb1.print();
	cout << endl << "Date of DOb2 : ";
	DOb2.print();
}

int main()
{
	PerformTask();
	return 0;
}
