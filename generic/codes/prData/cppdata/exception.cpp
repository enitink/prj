#include <iostream>

using namespace std;

class Exception
{};
 
void fun(int x)
{
	try{
       if (x==5)
              throw Exception();
       else
              cout<<x<<endl;
	}
	catch(...)
	{ cout << "caught exception" << endl; }
}
 
int main (void)
{
       for (int i=0;i<10;++i)
              fun(i);
       cout<<"Done"<<endl;
       return 0;
}
