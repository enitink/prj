#include <iostream>

using namespace std;

int main()
{
	int a = 10, b = 20, c = 30;

	cout << a << " " << b << " " << c << endl;
	(b = a) = c;

	cout << a << " " << b << " " << c << endl;

	return 0;
}
