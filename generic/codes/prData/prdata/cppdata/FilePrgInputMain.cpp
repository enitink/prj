#include"FilePrgOnObjects.h"
#include<fstream>

using std :: endl;
using std :: cout;
using std :: cin;
using std :: ofstream;
using std :: cerr;
using std :: ios;

int main()
{
	ofstream out("FilePrgOnObjects.txt", ios::binary);
	
	if (!out)
	{
		cerr << "File could Not Be Opened";
		exit( 1 );
	}
	
	Student Object;
	int No;
	
	cout << "Enter No of Terms U want to Use : ";
	cin >> No;
	
	int Size = sizeof( Student );
	
	for(int i = 0; i < No; ++i)
	{
		Object.EnterData();
		Object.DisplayData();
		out.write((char *) ( &Object ), Size);
	}
	
	cout << endl << "\n";
	
	return 0;
}