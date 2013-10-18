#ifndef _COMMON_BIG_INT_
#define _COMMON_BIG_INT_

#include <iostream>

#define SIZE 100 //more configuration required

using namespace std;

namespace gen { namespace common { namespace bigInt {

class gBigInteger
{
private:
	int data[SIZE];
	int len;
public:
	gBigInteger();
	gBigInteger(const gBigInteger& );

	gBigInteger& operator=(const gBigInteger& );
	const gBigInteger& operator+=(const gBigInteger& );
	gBigInteger& operator+(const gBigInteger& );
	
	const gBigInteger& operator*=(const gBigInteger& );
	gBigInteger& operator*(const gBigInteger& );
	
	friend ostream &operator<<( ostream &, const gBigInteger& );
	friend istream &operator>>( istream &, gBigInteger& );
};

}}}

#endif
