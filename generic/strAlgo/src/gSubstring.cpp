#include <cstring>
#include <gSubstring.h>

namespace gen { namespace str { namespace substring {

/*******************************************************************************
Name				:	longestSubsStringLen
Description			:	Finds out length of max common substring  of  given two
						strings. eg. stra = "exLen", strb = "Len"
						result = 3, for "Len" being max longest substring.
Problem type 		:	Dynamic Programming
Sol Explaination	:	
							L	e	n
						e	0	0	0
						x	0	0	0
						L	1	0	0
						e	0	2	0
						n	0	0	3
*******************************************************************************/

int gSubstring::longestSubstringLen(const char* stra, const char* strb)
{
	int lenStra = strlen(stra);
	int lenStrb = strlen(strb);
	int minStrLen, maxStrLen;
	bool prevRow = false;
	const char *pMinStr, *pMaxStr;
	
	if (lenStra < lenStrb)
	{ minStrLen = lenStra; maxStrLen = lenStrb; pMinStr = stra; pMaxStr = strb; }
	else
	{ minStrLen = lenStrb; maxStrLen = lenStra; pMinStr = strb; pMaxStr = stra; }


	int data[2][minStrLen+1];
	memset(data[0], 0, sizeof(int) * (minStrLen+1));
	memset(data[1], 0, sizeof(int) * (minStrLen+1));
	
	int result = 0;

	for (int i = 0; i < maxStrLen; ++i)
	{
		prevRow = !prevRow;
		
		for (int j = 1; j <= minStrLen; ++j)
		{
			if (pMaxStr[i] == pMinStr[j - 1])
			{	
				data[(int)prevRow][j] = data[(int) (!prevRow)][j - 1] + 1;
				result = (data[(int)prevRow][j] > result) ?  data[(int)prevRow][j] : result;
			}
			else
				data[(int)prevRow][j] = 0;
		}
	}
	return result;
}

/*******************************************************************************
Name				:	longestSubstringN
Description			:	Returns pointer to a new max common substring for given 
						two strings. eg. stra = "exLen", strb = "Len", result =
						"Len" being max longest substring. User should call del-
						ete as returned pointer created using new.
Problem type 		:	Dynamic Programming
Sol Explaination	:	
							L	e	n
						e	0	0	0
						x	0	0	0
						L	1	0	0
						e	0	2	0
						n	0	0	3
*******************************************************************************/

char* gSubstring::longestSubstringN(const char* stra, const char* strb)
{
	int lenStra = strlen(stra);
	int lenStrb = strlen(strb);
	int minStrLen, maxStrLen;
	bool prevRow = false;
	const char *pMinStr, *pMaxStr;
	
	if (lenStra < lenStrb)
	{ minStrLen = lenStra; maxStrLen = lenStrb; pMinStr = stra; pMaxStr = strb; }
	else
	{ minStrLen = lenStrb; maxStrLen = lenStra; pMinStr = strb; pMaxStr = stra; }


	/*int data[2][minStrLen+1];
	memset(data[0], 0, sizeof(int) * (minStrLen+1));
	memset(data[1], 0, sizeof(int) * (minStrLen+1));
	
	int result = 0;

	for (int i = 0; i < maxStrLen; ++i)
	{
		prevRow = !prevRow;
		
		for (int j = 1; j <= minStrLen; ++j)
		{
			if (pMaxStr[i] == pMinStr[j - 1])
			{	
				data[(int)prevRow][j] = data[(int) (!prevRow)][j - 1] + 1;
				result = (data[(int)prevRow][j] > result) ?  data[(int)prevRow][j] : result;
			}
			else
				data[(int)prevRow][j] = 0;
		}
	}*/
	char* result = new char[10];
	memset(result, 0, 10);
	result[0] = 'a'; result[1]='b'; result[2]='\n';
	return result;
}

}}}
