// This program code has been written by Nitin Kumar. For studying and is solely for studying and not for bigger use.

#include <iostream>

using std :: cout;
using std :: cin;
using std :: ostream;
using std :: istream;
using std :: endl;
using std :: cerr;

#include "NString.h"

int StrLen(char *ptr)
{
	int ln = 0;
	int i = 0;
	while(*(ptr + i) != '\0')
	{
		++ln;
		++i;
	}
	return ln;
}

void StrCpy(char *ptr, char *str)
{
	int ln = StrLen(str);
	int i;
	
	for(i = 0; i < ln ; ++i)
		*(ptr + i) = *(str + i);

    	*(ptr + i) = '\0';
}

ostream & operator<<( ostream & output, const String & s)
{
	output << s.ptr;
	return output;

}

istream & operator>>( istream & input, String & s)
{
	int ln = s.length;
	char *temp = new char[ 100 ];
	
	input.getline(temp , 100 ,'\n');
	
	for(int i = ln ; i < 100; ++i)
		temp[ i ] = '\0';

	String str(temp);

	
	s = str;

	return input;
}

String :: String()
{   
	ptr = new  char [100];
	for( int i = 0; i < 100; ++i)
		*(ptr + i) = '\0';
	length = 100;
}

String :: String(int l)
{
	ptr = new char[l + 1];
	for( int i = 0; i < l + 1; ++i)
		*(ptr + i) = '\0';
	length = l;
}

String :: String(char *str)
{
	length = StrLen(str);
	ptr = new char[length + 1];
	StrCpy(ptr, str);	
}


String :: String(const String &str)
{
	length = str.length;
	ptr = new char[length + 1];
	StrCpy(ptr, str.ptr);
}

String :: ~String()
{
   	delete [] ptr;
}

boolean String :: operator==(const String str)
{
	String pt(ptr);
	int lnstr = Length(str);
	int lnptr = Length(pt);
	int check = 1;

	if(lnstr == lnptr)
		for(int i = 0; i < lnstr ; ++i)
			check *= (str.ptr[i] == pt.ptr[i] ? 1 : 0);
	else
		check = 0;

	return  (check == 1) ? TRUE : FALSE;
}

boolean String :: operator>=(String str)
{
	String st(ptr);
	return ((st > str) || (st == str)) ? TRUE : FALSE;
}

boolean String :: operator<=(String str)
{
	String st(ptr);
	return ((st < str) || (st == str)) ? TRUE : FALSE;
}

boolean String :: operator>(String str)
{
	int lnstr = Length(str);
	int lnptr = Length(ptr);
	int check = 1;
	int min = lnptr;

	if(lnstr < lnptr)
		min = lnstr;
	
	for(int i = 0; i < min ; ++i)
	{
		if(ptr[i] > str.ptr[i])
		{
			check = 1;
			break;
		}
		else
		{	
			if(ptr[i] == str.ptr[i])
			{
				check = 0;
				continue;
			}
			else
			{
				check = 0;
				break;
			}
		}
	}
	
	return  (check == 1) ? TRUE : FALSE;
}

boolean String :: operator<(String str)
{
	int lnstr = Length(str);
	int lnptr = Length(ptr);
	int check = 1;
	int min = lnptr;

	if(lnstr < lnptr)
		min = lnstr;
	
	for(int i = 0; i < min ; ++i)
	{
		if(ptr[i] < str.ptr[i])
		{
			check = 1;
			break;
		}
		else
		{	
			if(ptr[i] == str.ptr[i])
			{
				check = 0;
				continue;
			}
			else
			{
				check = 0;
				break;
			}
		}
	}
	
	return  (check == 1) ? TRUE : FALSE;
}

boolean String :: operator!=(const String str)
{
	return (ptr == str.ptr) ? FALSE : TRUE;
}

String String :: operator+(const String str)
{
	int lnstr = Length(str);
	int lnptr = Length(ptr);
	int i,j;
	
	String st(lnstr + lnptr);

	for(i = 0; i < lnptr; ++i)
		st.ptr[i] = ptr[i];
	for(j = 0; j < lnstr ; ++i , ++j)
		st.ptr[i] = str.ptr[j];
	
	st.ptr[lnstr + lnptr] = '\0';

	return st;
}

void String :: operator+=(const String str)
{
	String pt(ptr);
	int lnstr = Length(str);
	int lnptr = Length(pt);
	int i,j;
	
	ptr = new char[lnstr + lnptr + 1];

	for(i = 0 ; i < lnptr ; ++i)
		ptr[i] = pt.ptr[i];
	for(j = 0 ; j < lnstr; ++i, ++j)
		ptr[i] = str.ptr[j];
	
	ptr[i] = '\0';

}

void String :: operator=(const String str)
{
	int ln = Length(str);

	ptr = new char[ln + 1];

	StrCpy(ptr,str.ptr);
	length = Length(str);
}

String SubString(const String st,int from, int to)
{
	int ln = Length(st);
	int i,j = 0;

	String temp(to);

	for(i = (from - 1) ; i < (from + to)  && i < ln; ++i)
	{
		temp.ptr[j] = st.ptr[i];
		++j;
	}

	temp.ptr[to] = '\0';
	
	return temp;
}


String Left(const String st, int l)
{
	int i;
	String temp(l);

	for(i = 0 ; i < l ; ++i )
		temp.ptr[i] = st.ptr[i];

	temp.ptr[l] = '\0';

	return temp;
}

String Right(const String st, int r)
{
	int ln = Length(st);
	int i,j;
	String temp(r);

	for(i = ln - 1, j = r - 1 ; i >= 0 && j >= 0 ; --i , --j)
		temp.ptr[j] = st.ptr[i];

	temp.ptr[r] = '\0';

	return temp;
}

String Reverse(const String st)
{
	int ln = Length(st);
	int i,j;

	String temp(ln);

	for(i = (ln - 1) , j = 0; i >= 0 && j < ln; --i , ++j)
		temp.ptr[j] = st.ptr[i];

	temp.ptr[ln] = '\0';

	return temp;
}

String Rtrim(const String st)
{
	int ln = Length(st);
	int i;
	int pos = 0;
	
	for(i = ln - 1; i >= 0; --i)
		if(st.ptr[i] != ' ')
		{
			pos = i;
			break;
		}

	if(pos == 0)
		return st;
	else
	{
		String temp(pos + 1);

		for(i = 0; i <= pos ; ++i)
			temp.ptr[i] = st.ptr[i];
		
		temp.ptr[pos + 1] = '\0';		
		
		return temp;
	}
}


String Ltrim(const String st)
{
	int ln = Length(st);
	int i;
	int pos = 0;
	
	for(i = 0; i < ln ; ++i)
		if(st.ptr[i] != ' ')
		{
			pos = i;
			break;
		}

	if(pos == 0)
		return st;
	else
	{
		String temp(ln - pos);
		for(i = pos ; i < ln ; ++i)
			temp.ptr[i - pos] = st.ptr[i];

		temp.ptr[ln  - pos] = '\0';

		return temp;
	}
}

String Alltrim(const String st)
{
	String temp(st);

	temp = Ltrim(temp);
	temp = Rtrim(temp);

	return temp;
}

String ToLower(const String st)
{
	int ln = Length(st);
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(temp.ptr[i] >= 65 && temp.ptr[i] < 91)
			temp.ptr[i] += 32;
	}

	return temp;
}

String ToUpper(const String st)
{
	int ln = Length(st);
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(temp.ptr[i] > 96 && temp.ptr[i] < 123)
			temp.ptr[i] -= 32;
	}

	return temp;
}

String Proper(const String st)
{
	int ln = Length(st);
	int check = 1;
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(check == 1)
			temp.ptr[i] = temp.ptr[i] > 96 && temp.ptr[i] < 123 ?
								 (temp.ptr[i] - 32) : (temp.ptr[i]);
		else
			temp.ptr[i] = (temp.ptr[i] >= 65 && temp.ptr[i] < 91 ?
								 (temp.ptr[i] + 32) : (temp.ptr[i]));

		if(temp.ptr[i] == ' ')
			check = 1;
		else
			check = 0;

	}

	return temp;
}

String Stuff(const String st, char c)
{
	int ln = Length(st);
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
		if(temp.ptr[i] == ' ')
			temp.ptr[i] = c;
	return temp;
}


String Replace(const String str, const String st,const String s)
{
	int lnstr = Length(str);
	int lnst  = Length(st);
	int lns   = Length(s);
    	int replacepos = FindPos(str, st);
    	int lntemp;
	int i,j;

	if(lns != lnst)
	{
		cout << "Invalid String Entry : Strings Should Be of Equal Length";
		return str;
	}
	lntemp = lnstr - lnst + lns;

	String temp(lntemp + 1);
    
	if(replacepos == -1)
	{
		cout << "String not found";
		return str;
	}
	else
	{
		for( i = 0 ; i < replacepos - 1 ; ++i)
			temp.ptr[i] = str.ptr[i];
		for( j = 0 ; j < lns ; ++i , ++j)
			temp.ptr[i] = s.ptr[j];
		for(j = replacepos + lns - 1; j < lnstr && i < lntemp; ++j , ++i)
			temp.ptr[i] = str.ptr[j];


        temp.ptr[lntemp] = '\0';
		
		return temp;
	}
}

String Insert(const String str, const String st, int pos)
{
	int lnstr = Length(str);
	int lnst  = Length(st);
	int i,j;
	int lntemp = lnstr + lnst; 

	String temp(lntemp + 1);

	for( i = 0; i < pos ; ++i)
		temp.ptr[i] = str.ptr[i];
	for( j = 0; j < lnst ; ++i, ++j)
		temp.ptr[i] = st.ptr[j];
	for(j = pos ; j < lnstr ; ++j , ++i)
		temp.ptr[i] = str.ptr[j];

	temp.ptr[lntemp] = '\0';

	return temp;
}

String Remove(const String str, const String st)
{
	int lnstr = Length(str);
	int lnst  = Length(st);
	int removepos = FindPos(str, st);
    	int i,j;
	int lntemp = lnstr - lnst; 

	String temp(lntemp);

	if(removepos == -1)
	{
		cout << "String not found";
		return str;
	}
	else
	{
		for(i = 0 ; i < removepos - 1; ++i)
			temp.ptr[i] = str.ptr[i];
		for(j = removepos + lnst - 1; j < lnstr ; ++i , ++j)
			temp.ptr[i] = str.ptr[j];
		
		temp.ptr[lntemp] = '\0';

		return temp;
	}
}

String Lshift(const String st, int no)
{
	int lnstr = Length(st);
	
	if((no < 0) || (no > lnstr))
	{
		cout << "Lshift Not Possible";
		return st;
	}
	
	String temp(lnstr + 1);

	for(int i = lnstr ; i >= no ; --i)
		temp.ptr[i - no] = st.ptr[i];

	temp.ptr[lnstr - no] = '\0';
	
	return temp;
}

String Rshift(const String st, int no)
{
	int lnstr = Length(st);
	
	if((no < 0) || (no > lnstr))
	{
		cout << "Rshift Not Possible";
		return st;
	}

	String temp(lnstr - no);

	for(int i = 0 ; i < lnstr - no ; ++i)
		temp.ptr[i] = st.ptr[i];

	temp.ptr[lnstr - no] = '\0';
	
	return temp;
}

boolean Palindrome(const String st)
{
	int lnstr = Length(st);
	String temp(lnstr);

	temp = Reverse(st);

	return ((temp == st) ? TRUE : FALSE);
}

boolean Find(const String str, const String st)
{
	int lnstr = Length(str);
	int lnst = Length(st);
	int check = 1;

	for(int i = 0; i < lnstr ; ++i)
	{ 
		check = 1;
		for(int j = 0; j < lnst; ++j)
			check *= ((str.ptr[i + j] == st.ptr[j]) ? 1 : 0);
		
		if(check == 1) 
			return TRUE;
		else
			continue;
	}		

	return FALSE;	
}

boolean IsUpper(const String st, int upto)
{
	int lnstr = Length(st);
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(st.ptr[i] != ' ')
		{
			check *= ((st.ptr[i] >= 65 && st.ptr[i] < 91) ? 1 : 0);
			if(check == 0)
				break;
		}
		else
			check *= 1;
	}
		
	return (check == 1) ? TRUE : FALSE;
}

boolean IsLower(const String st, int upto)
{		
	int lnstr = Length(st);
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(st.ptr[i] != ' ')
		{
			check *= (st.ptr[i] > 96 &&  st.ptr[i] < 123) ? 1 : 0;
			if(check == 0)
				break;
		}
		else
			check *= 1;
	}

	return (check == 1) ? TRUE : FALSE;
}

boolean IsAlpha(const String st, int upto)
{
	int lnstr = Length(st);
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(st.ptr[i] != ' ')
		{
			check *= (st.ptr[i] > 96 &&  st.ptr[i] < 123)
						|| (st.ptr[i] >= 65 &&  st.ptr[i] < 91) ? 1 : 0;
			if(check == 0)
				break;
		}
		else
			check *= 1;
	}

	return (check == 1) ? TRUE : FALSE;
}


boolean IsNum(const String st, int upto)
{	
	int lnstr = Length(st);
	int check = 1;
	int ch = 0;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		check *=     (st.ptr[i] >= '0')
				  && (st.ptr[i] <= '9')
				  || (st.ptr[i] == '.') ? 1 : 0;
		if(st.ptr[i] == '.')
		{
			++ch;
			if(ch > 1)
				check = 0;
		}
		if(check == 0)
			break;
	}

	return (check == 1) ? TRUE : FALSE;
}

int Length(const String st)
{
	int i = 0;
	int len = 0;

	while(st.ptr[i] != '\0')
	{
		++i;
		++len;
	}
	return (len);
}

int FindPos(const String str, const String st)
{
	int lnstr = Length(str);
	int lnst = Length(st);
	int check = 1;

	for(int i = 0; i < lnstr ; ++i)
	{ 
		check = 1;
		for(int j = 0; j < lnst; ++j)
			check *= (str.ptr[i + j] == st.ptr[j]) ? 1 : 0;

		if(check == 1) 
			return i+1;
		else
			continue;
	}		

	return -1;
}					

char Charat(const String st, int pos)
{
	int lnstr = Length(st);
	return (pos >= 0 && pos < lnstr) ? st.ptr[pos - 1] : 'N';
}

double DouValue(const String st)
{
	int lnstr = Length(st);
	int check = 0;
	int counter = 0;
	
	double num = 0;
	double dec = 0;

	if(IsNum(st,lnstr))
	{
		for(int i = 0 ; i < lnstr; ++i)
		{
			if(st.ptr[i] == '.')
			{
				check = 1;
				continue;
			}
			if(check != 1)
				num = num * 10 + Int(st.ptr[i]);
			else
			{	
				dec = (dec* 10) + Int(st.ptr[i]);		
				++counter;
			}
		}
	}
	else
		cerr << "Non Numeric data Type";

	for(int i = 0; i < counter; ++i)
		dec /= 10;	
	return (num + dec);
}

int IntValue(const String st)
{	
	int lnstr = Length(st);
	int check = 0;
	
	int num = 0;
	
	if(IsNum(st, lnstr))
	{
		for(int i = 0 ; i < lnstr; ++i)
		{
			if(st.ptr[i] == '.')
			{
				cout << "Non Numeric data Type";
				return 0;		
			}
			
			num = num * 10 + Int(st.ptr[i]);
		}
	}
	else
		cerr << "Non Numeric data Type";

	return num;
}

int Int(const char c)
{
	return (c >= '0' || c <= '9') ? c - '0' : 0;
}
