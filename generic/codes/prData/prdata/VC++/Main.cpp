#include<iostream>
using namespace std;

#include"NString.h"

int main()
{
	String ob,ob1,ob2;
	
	cout << "Enter any String : ";
	cin >> ob;

	cout << "Enter Second String : ";
	cin >> ob1;

	cout << endl << "String ob is : " << DouValue(ob);
	cout << endl << "String ob1 is : " << IntValue(ob1) << endl;
	
	return 0;
}

