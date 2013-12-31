#include <cstring>
#include <gBigInteger.h>

namespace gen { namespace common { namespace bigInt {

gBigInteger::gBigInteger()
	: 	__pData(NULL)
	,	__len(0)
	,	__positive(true)
{}

gBigInteger::gBigInteger(int size)
	: 	__pData(NULL)
	,	__len(0)
	,	__positive(true)
{
	try{
		__pData = new u4_t[size];
		__len = size;
		__positive = true;
	}
	catch(...)
	{
		if (__pData)
			delete [] __pData;
		__len = 0;
	}
}

gBigInteger::gBigInteger(const gBigInteger& rhs)
	: 	__pData(NULL)
	,	__len(0)
	,	__positive(true)
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
	*this = *this + rhs;
	return *this;
}

gBigInteger gBigInteger::operator+(const gBigInteger& rhs)
{
	if (__positive == rhs.__positive)
	{
		gBigInteger t1_g;
		gBigInteger t2_s;
		
		if ( __len > rhs.__len )
		{
			t1_g = *this;
			t2_s = rhs;
		}
		else
		{
			t1_g = rhs;
			t2_s = *this;
		}
		
		int l_diff = t1_g.__len - t2_s.__len;
		int i = 0;
		u32_t s = 0;
		u32_t r = 0;	
		for (i = t2_s.__len - 1; i >= 0; --i)
		{
			s = (t1_g.__pData[i + l_diff].n + t2_s.__pData[i].n + r) % 10;
			r = (t1_g.__pData[i + l_diff].n + t2_s.__pData[i].n + r) / 10;
			t1_g.__pData[i + l_diff].n = s;
		}
		for (i = t1_g.__len - t2_s.__len - 1; i >= 0; --i)
		{
			s = (t1_g.__pData[i].n + r) % 10;
			r = (t1_g.__pData[i].n + r) / 10;
			t1_g.__pData[i].n = s;
		}
		
		if ( (i == -1) && (r) )
		{
			gBigInteger tt_ob(t1_g.__len + 1);
			memcpy(&tt_ob.__pData[1], t1_g.__pData, sizeof(u4_t) * t1_g.__len);
			tt_ob.__pData[0].n = r;
			t1_g = tt_ob;
		}
		t1_g.__positive = __positive;
		return t1_g;
	}

	gBigInteger t1_g;
	return t1_g;
}

gBigInteger gBigInteger::operator-(const gBigInteger& )
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
		input >> chStr;

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
	reset();
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
		delete [] __pData;
	__pData = NULL;
	__len = 0;
	__positive = true;
}

}}}
