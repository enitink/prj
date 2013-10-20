#include<iostream.h>
#include<fstream.h>

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
			while(c != EOF)
			{
			   cin.get(c);
			   out << c;
			}
		}
		out.close();
	}
	return 0;
}
