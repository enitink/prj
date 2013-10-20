#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

class FPS
{
private :
	int feet;
	int inch;
public :
	FPS()
	{
		feet = 0;
		inch = 0;
	}
	FPS(int feet, int inch)
	{
		this->feet = feet;
		this->inch = inch;
		
		while(this->inch >= 12)
		{
			this->inch -= 12;
			this->feet += 1;
		}
	}
	void SetData(int feet, int inch)
	{
		this->feet = feet;
		this->inch = inch;
		
		while(this->inch >= 12)
		{
			this->inch -= 12;
			this->feet += 1;
		}
	}
	void DisplayData()
	{
		cout << feet << "\"" << inch << "'";
		cout << endl;
	}
	FPS operator++()
	{
		SetData(++feet,++inch);
		return *this;
	}
	FPS operator++(int)
	{
		return FPS(feet++,inch++);		
	}
};

int main()
{
	FPS ob,ob1,ob2;
	int feet,inch;
	
	cout << endl << "Enter Distance : (feet, inch) : ob :";
	cin >> feet >> inch;	
	ob.SetData(feet,inch);
	cout << endl << "Enter Distance : (feet, inch) : ob1 :";
	cin >> feet >> inch;	
	ob1.SetData(feet,inch);	
	
	ob2 = ++ob;
	++ob1;
	
	cout << endl << "ob : ";
	ob.DisplayData();
	cout << endl << "ob1 : ";
	ob1.DisplayData();
	cout << endl << "ob2 : ";
	ob2.DisplayData();
	
	ob2 = ob++;
	ob1++;
	
	cout << endl << "ob : ";
	ob.DisplayData();
	cout << endl << "ob1 : ";
	ob1.DisplayData();
	cout << endl << "ob2 : ";
	ob2.DisplayData();
	
	cout  << "\n";
	return 0;
}
