#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<iomanip>

using std :: setw;

class  Complex
{
private :
	int real;
	int imag;
public  :
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(int real, int imag)
	{
		this->real = real;
		this->imag = imag;
	}
	void SetData(int real, int imag)
	{
		this->real = real;
		this->imag = imag;
	}
	void DisplayData()
	{
		cout << real;
		if(imag < 0)
			cout << " - i" << (-1 * imag);
		else
			if(imag > 0)
				cout << " + i" << imag;
	}
	Complex operator+(Complex N)
	{
		return Complex(real + N.real, imag + N.imag);
	}
	Complex operator*(Complex N)
	{
		return Complex((real * N.real) - (imag * N.imag), (real * N.imag) + (imag * N.real));
	}
	void operator=(Complex N)
	{
		real = N.real;
		imag = N.imag;
	}
};

int main()
{
	Complex ob,ob1,ob2;
	int real,imag;
	
	cout << endl << "Enter Complex no : ob : (a + ie) : ";
	cin >> real >> imag;
	ob.SetData(real,imag);
	
	cout << endl << "Enter Complex no : ob1 : (a + ie) : ";
	cin >> real >> imag;
	ob1.SetData(real,imag);
	
	cout << endl << "Complex no. : ob = ";
	ob.DisplayData();
	cout << endl << "Complex no. : ob1 = ";
	ob1.DisplayData();
	
	ob2 = ob + ob1;
	cout << endl << "Complex no. : ob + ob1 = ";
	ob2.DisplayData();
	
	ob2 = ob * ob1;
	cout << endl << "Complex no. : ob * ob1 = ";
	ob2.DisplayData();
	
	cout << endl;
	return 0;
}

