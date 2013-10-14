//Find longest common substring from two given string
#ifndef _LONGEST_COMM_SUBSTRING_
#define _LONGEST_COMM_SUBSTRING_

namespace gen { namespace str { namespace substring {

class gSubstring
{
public:
	static int longestSubstringLen(const char*, const char*);
	static char* longestSubstringN(const char*, const char*); //Returns a pointer, that user should clear
};

}}} //gen::str::substring

#endif //_LONGEST_COMM_SUBSTRING_ 
