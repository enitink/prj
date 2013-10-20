#include <iostream>

#define mySizeOfOperator(X) ((int)(( (X*) 0) + 1) - (int)((X*) 0))

using namespace std;

int main()
{
	cout << endl << "SizeOf int " << mySizeOfOperator(int);
	cout << endl << "SizeOf char " << mySizeOfOperator(char);
	cout << endl << "SizeOf float " << mySizeOfOperator(float);
	cout << endl << "SizeOf double " << mySizeOfOperator(double);
	cout << endl << "SizeOf short int " << mySizeOfOperator(short int);
	return 0;
}
