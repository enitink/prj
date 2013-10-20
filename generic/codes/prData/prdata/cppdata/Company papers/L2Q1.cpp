#include<iostream>

using std :: cout;
using std :: endl;

int main()
{
	int *a, *s , i;
	
	s = a = new int[4];
	
	for( i = 0; i < 4; ++i) a[i] = i * 10;
	
	
	cout << endl << "*(s++) : " << *(s++);
	cout << endl << "(*s)++ : " << (*s)++;
	cout << endl << "*s : " << *s;
	cout << endl << "*(++s) : " << *(++s);
	cout << endl << "++(*s) : " << ++(*s);
	
	cout << endl;
	return 0;
}