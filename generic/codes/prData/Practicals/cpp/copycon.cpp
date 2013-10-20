#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<fstream>

using std :: ofstream;

int main(int argc,char *argv[])
{
	if(argc > 1)
	{
		ofstream out(argv[1]);
		char c;
		
		if(out == NULL)
		{
			cout << endl << "File Cannot be Opened";
			exit(0);
		}
		else
		{
			while(c != EOF)
			{
			   cin.get(c);
			   out << c;
			}
		}
		
		out.close();
	}
	else
	{
		cout << "Too Few Parameters to Call copycon";
	}
	
	cout << endl;                   
}
