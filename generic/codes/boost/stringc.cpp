#include <string>
#include <iostream>

using namespace std;

int main()
{
	string currline("HEllo my name. is nitin. kumar 1.1");
	std::size_t found = currline.find('.');
	while(1)
	if ((found!=std::string::npos) && (isdigit(currline[found-1])))
	{
		cout << currline[found+1] << currline[found+2] << endl; 
		break;
	}
	return 0;
}
