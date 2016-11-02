#ifndef _COMMON_BIG_INT_
#define _COMMON_BIG_INT_

#include <iostream>
#include <gCommonDefs.h>

using std::ostream;
using std::istream;
using namespace gen::common::defs;

namespace gen { namespace common { namespace bigInt {

class gBigInteger
{
public:
	gBigInteger();
	gBigInteger(const gBigInteger& );

	~gBigInteger();

	gBigInteger& operator=(const gBigInteger& );
	const gBigInteger& operator+=(const gBigInteger& );
	gBigInteger operator+(const gBigInteger& );

	gBigInteger operator-(const gBigInteger& );	
	const gBigInteger& operator*=(const gBigInteger& );
	gBigInteger operator*(const gBigInteger& );
	
	friend ostream &operator<<( ostream &, const gBigInteger& );
	friend istream &operator>>( istream &, gBigInteger& );

private:
	explicit gBigInteger(int size);
	void copyData(const gBigInteger& );
	bool findLen(const char* );
	void reset();
private:
	u4_t* 	__pData;
	int 	__len;
	bool	__positive;
};

}}}

#endif
