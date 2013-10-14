#include <iostream>

using std::cout;
using std::endl;

#include "gSubstring.h"
using namespace gen::str::substring; //::gSubstring::longestSubstringLen;

int main(int argC, char** argV)
{
	if (argC != 3)
	{
		cout << "invalid input: eg. <executable> <string1> <string2>" << endl;
		return 1;
	}
	cout << gSubstring::longestSubstringLen(argV[1], argV[2]) << endl;
	char* ptr = gSubstring::longestSubstringN(argV[1], argV[2]);
	cout << ptr;
	delete [] ptr;
	return 0;
}
