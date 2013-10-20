#include<iostream>

using std :: cout;
using std :: endl;

#define line    cout << endl << "Hey ! how can u do that"; cout << endl << "IDIOT";
#define line1 { cout << endl << "Hey ! how can u do that"; cout << endl << "IDIOT"; }

int main()
{
	for(int i = 0; i < 2; ++i)
	{
		if(i == 0)
			line;

		if(i == 1)
			line1;
	}
	
	cout << endl;
	return 0;
}