#include"FilePrgOnObjects.h"
#include<fstream>

using std :: endl;
using std :: cout;
using std :: cin;
using std :: ifstream;
using std :: cerr;
using std :: ios;

int main()
{
	ifstream in("FilePrgOnObjects.txt", ios::in);
	
	if (!in)
	{
		cerr << "File could Not Be Opened";
		exit( 1 );
	}
	
	Student Object;
	int No;
	
	int Size = sizeof( Student );
	
	while(!in.eof())
	{
		in.read((char *) ( &Object ), Size);
		Object.DisplayData();
	}
	
	cout << endl << "\n";
	
	return 0;
}