#include <iostream>
#include <string>
#include <cstdlib>
#include <myFirstCgi.h>

using namespace std;
using namespace cgi::lib;

int main()
{
	MyFirstCgi ob;
	
	ob.prepareRspString();
	cout << ob.getRespString();
	
	return 0;
}
