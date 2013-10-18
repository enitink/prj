#include <iostream>

using std::cout;
using std::endl;

#include "gSubstring.h"
using namespace gen::str::substring; //::gSubstring::longestSubstringLen;

#include "gStringPerm.h"
using namespace gen::str::stringPerm;
 
int main(int argC, char** argV)
{
	/*if (argC != 3)
	{
		cout << "invalid input: eg. <executable> <string1> <string2>" << endl;
		return 1;
	}
	cout << gSubstring::longestSubstringLen(argV[1], argV[2]) << endl;
	char* ptr = gSubstring::longestSubstringN(argV[1], argV[2]);
	cout << ptr;
	delete [] ptr;*/

	if (argC != 2)
	{
		cout << "invalid input: eg. <executable> <string1>" << endl;
		return 1;
	}

	cout << gStringPerm::stringRank(argV[1]);
	return 0;
}
