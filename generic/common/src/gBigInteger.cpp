#include <cstring>
#include <gBigInteger.h>

using std::cin;
using std::cout;

namespace gen { namespace common { namespace bigInt {

gBigInteger::gBigInteger()
	: 	__pData(NULL)
	,	__len(0)
	,	__positive(true)
{}

gBigInteger::gBigInteger(const gBigInteger& rhs)
{
	copyData(rhs);
}

gBigInteger::~gBigInteger()
{
	reset();
}

gBigInteger& gBigInteger::operator=(const gBigInteger& rhs)
{
	if (this != &rhs)
	{
		copyData(rhs);
	}
	return *this;
}

const gBigInteger& gBigInteger::operator+=(const gBigInteger& rhs)
{
}

gBigInteger& gBigInteger::operator+(const gBigInteger& rhs)
{
}

const gBigInteger& gBigInteger::operator*=(const gBigInteger& rhs)
{
}

gBigInteger& gBigInteger::operator*(const gBigInteger& rhs)
{
}

ostream & operator<<( ostream & output, const gBigInteger& s)
{
	output << ((s.__positive)? "" : "-");
	for (int i = 0; i < s.__len; ++i)	
		output << s.__pData[i].n;
	return output;
}

istream & operator>>( istream & input, gBigInteger& s)
{
	char* chStr = NULL;
	try {
		chStr = new char[1000];
		memset(chStr, 0, 1000);
		cin >> chStr;

		s.reset();
	
		int i = 0, j = 0;
		j += (s.findLen(chStr)) ? 1 : 0 ;
		
		s.__pData = new u4_t[s.__len];

		for(; i < s.__len ; ++i)
			s.__pData[ i ].n = chStr[i+j] - '0';

		delete [] chStr;
	}
	catch (...)
	{
		if ( chStr != NULL)
			delete [] chStr;
		if ( s.__pData )
			s.reset();
	}
	return input;
}

void gBigInteger::copyData(const gBigInteger& rhs)
{
	__len = rhs.__len;
	__positive = rhs.__positive;

	try
	{
		__pData = new u4_t[__len];
		memcpy(__pData, rhs.__pData, __len * sizeof(int));
	} catch(...)
	{
		if (__pData != NULL)
			delete [] __pData;
	}
}

bool gBigInteger::findLen(const char* ptr)
{
	int i = 0;
	bool firstCharSign = false;
	if ( (ptr[i] == '-') )
	{
		__positive = false;
		++i;
		firstCharSign = true;
	}
	else if ( ptr[i] == '+' )
	{
		++i;
		firstCharSign = true;
	}
	while ( ptr[i])
	{
		if (! ((ptr[i] <= '9') && (ptr[i] >= '0')) )
		{
				break;
		}
		++i;
		++__len;
	}
	return firstCharSign;
}

void gBigInteger::reset()
{
	if ( __pData )
	{
		delete [] __pData;
		__pData = NULL;
	}
	__len = 0;
	__positive = true;
}

}}}
