#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

template <class T>

T Max(T x, T y)
{
	if(x > y)
		return x;
	else
		return y;
}

int main()
{
	int x,y;
	float a,b;

	cout << "Enter two Int numbers   : ";
	cin >> x >> y;

	cout << "Enter two Float numbers : ";
	cin >> a >> b;

	cout << endl << "MAX between Int nos is   : " << Max(x,y);
	cout << endl << "MAX between Float nos is : " << Max(a,b);

	cout << "\n";
	return 0;
}
