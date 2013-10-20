#include<iostream>

using std :: cout;
using std :: cin;
using std :: endl;

#include<fstream>

using std :: ofstream;

int main(int argc,char *argv[])
{
	ofstream out(argv[1]);
	char c;

	if(argc > 1)
	{
		if(out==NULL)
			cout << "\n The specified file name or path is invalid";
		else
		{
			do 
			{
			   cin.get(c);
			   out << c;
			}while(c != EOF);
		}
		out.close();
	}
	return 0;
}
