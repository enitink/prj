//Find lexicographic rank of a string. Given a string find all it's permulations sorted lexicographically,
//for example, rank of "abc" is 1, rank of "acb" is 2, and rank of "cba" is 6.
#ifndef _LONGEST_COMM_STRING_PERM_
#define _LONGEST_COMM_STRING_PERM_

namespace gen { namespace str { namespace stringPerm {

class gStringPerm
{
public:
	static int stringRank(const char*);
};

}}} //gen::str::stringPerm

#endif //_LONGEST_COMM_STRING_PERM_ 
