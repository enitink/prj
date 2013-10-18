#include <cstring>
#include <gBigInteger.h>

namespace gen { namespace common { namespace bigInt {

gBigInteger::gBigInteger()
	: len(0)
{}
gBigInteger::gBigInteger(const gBigInteger& rhs)
{
	len = rhs.len;
	memcpy(data, rhs.data, len * sizeof(int));
}

gBigInteger& gBigInteger::operator=(const gBigInteger& rhs)
{
	if (this != &rhs)
	{
		len = rhs.len;
		memcpy(data, rhs.data, len * sizeof(int));
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
	for (int i = 0; i < s.len; ++i)	
		output << s.data[i];
	return output;
}

istream & operator>>( istream & input, gBigInteger& s)
{
	char chStr[SIZE];
	cin >> chStr;

	for(int i = 0; ; ++i)
	{
		if ( chStr[i] == '\0')
		{
			break;
		}
		s.data[ i ] = chStr[i] - '0';
		++s.len;
	}

	return input;
}

}}}
