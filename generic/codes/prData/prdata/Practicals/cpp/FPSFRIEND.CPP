#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

class FPS
{
	friend FPS operator+(FPS,FPS);
private :
	int feet;
	int inch;
public :
	FPS()
	{
		feet = inch = 0;
	}
	FPS(int feet, int inch)
	{
		SetData(feet, inch);
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
		cout << feet << "\"" << inch << "'" << endl;
	}
};

FPS operator+(FPS D, FPS D1)
{
	return FPS(D.feet + D1.feet, D.inch + D1.inch);
}

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
	
	ob2 = ob + ob1;
	
	cout << endl << "ob : ";
	ob.DisplayData();
	cout << endl << "ob1 : ";
	ob1.DisplayData();
	cout << endl << "ob2 : ";
	ob2.DisplayData();
	
	return 0;
}
