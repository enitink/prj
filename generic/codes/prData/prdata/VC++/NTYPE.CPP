#include<iostream.h>
#include<fstream.h>

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	char c;

	if(argc > 1)
	{
		if(in==NULL)
			cout << "\n The specified file name or path is invalid";
		else
		{
			while(in)
			{
			   c = in.get();
			   cout << c;
			}
		}
		in.close();
	}
	return 0;
}
