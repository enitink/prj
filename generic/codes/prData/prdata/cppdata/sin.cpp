#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

void Sinx()
{
	double Degree;
	double Radian;
	double Sum;
	double Numerator;
	double Denominator;
	
	cout << endl << "Enter Degree : ";
	cin >> Degree;
	
	Radian = Degree * 3.14 / 180;
	Sum = 0;
	Numerator = Radian;
	Denominator = 1;
	
	for(int i = 1; i <= 100; i += 2)
	{
		Sum += (Numerator / Denominator);
		Numerator *= (Radian * Radian) * (-1);
		Denominator *= ((i + 1) * (i + 2));
	}
	
	cout << endl << "The Value of Sin(" << Degree << ") = " << Sum;
	
	return;
}

int main()
{
	Sinx();
	cout << endl;
	return 0;
}

