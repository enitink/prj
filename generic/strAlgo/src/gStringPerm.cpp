#include <cstring>
#include <gStringPerm.h>
#include <iostream>

using namespace std;

namespace gen { namespace str { namespace stringPerm {

/*******************************************************************************
Name				:	
Description			:	
Problem type 		:	
Sol Explaination	:	
*******************************************************************************/

int gStringPerm::stringRank(const char* str)
{
	int lenStra = strlen(str);
	int result = 1;
	int lowerCaseChar[2][26] = {};
	int upperCaseChar[2][26] = {};

	int i = 0;
	for ( ; i < lenStra; ++i )
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			++upperCaseChar[0][ str[i] - 'A' ];
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			++lowerCaseChar[0][ str[i] - 'a' ];
	}
	int tillNow = 0;
	for ( i=0; i < 26; ++i)
	{
		if (upperCaseChar[0][i])
		{
			upperCaseChar[1][i] = tillNow;
			++tillNow;
		}
	}
	for ( i=0; i < lenStra; ++i )
	{
		if (lowerCaseChar[0][i])
		{
			lowerCaseChar[1][i] = tillNow;
			++tillNow;
		}
	}

	for ( i=0; i < lenStra; ++i )
	{
		
	}
	return result;
}

}}}
