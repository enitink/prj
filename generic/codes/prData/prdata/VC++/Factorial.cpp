#include<iostream>

using std :: endl;
using std :: cin;
using std :: cout;

class Factorial
{
private :
	int n;		
public :
	void SetData(int n);
	int operator!();
};

void Factorial :: SetData(int n)
{
	this->n = n;
}

int operator!()
{
	return (n <= 1);// ? 1 : n * !(n - 1);
}

int main()
{
	Factorial Fact;
	int n;
	
	cout << "Enter Any No. To find out its factorial";
	cin >> n;
	Fact.SetData(n);
	Fact!;
	cout << "Factorial of Given No. " << n << " is ";

	return 0;
}
