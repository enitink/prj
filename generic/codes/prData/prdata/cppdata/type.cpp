#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<fstream>
using std :: ifstream;

int main(int argc, char *argv[])
{
	if(argc > 1)
 	{
		ifstream in(argv[1]);
		char c;

		if(in != NULL)
			while(in.eof() == 0)
			{
				in.get(c);
				cout << c;
			}
		else
		{
			cout << endl << "Specified file not fount";
			exit(0);
		}
		in.close();
	}
	else
	{
		cout << endl << "Too few parameters to call type";
	}
	cout << endl;
	return 0;
}
