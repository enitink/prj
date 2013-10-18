#include	<iostream>

using namespace std;

#include	<gString.h>

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
	int ln = StrLen(str); int i = 0;
	
	for( ; i < ln ; ++i)
		*(ptr + i) = *(str + i);

    *(ptr + i) = '\0';
}

ostream & operator<<( ostream & output, const gString & s)
{
	output << s.ptr;
	return output;

}

istream & operator>>( istream & input, gString & s)
{
	int ln = s.length;
	char *temp = new char[ 100 ];

	input.getline(temp , 100 ,'\n');
	
	for(int i = ln ; i < 100; ++i)
		temp[ i ] = '\0';

	gString str(temp);

	s = str;

	return input;
}

gString::gString()
{   
	ptr = new  char [100];
    for( int i = 0; i < 100; ++i)
		*(ptr + i) = '\0';
	length = 100;
}

gString::gString(int l)
{
	ptr = new char[l + 1];
	for( int i = 0; i < l + 1; ++i)
		*(ptr + i) = '\0';
	length = l;
}

gString::gString(char *str)
{
	length = StrLen(str);
	ptr = new char[length + 1];
	StrCpy(ptr, str);	
}


gString::gString(const gString &str)
{
	length = str.length;
	ptr = new char[length + 1];
	StrCpy(ptr, str.ptr);
}

gString::~gString()
{
   delete [] ptr;
}

boolean gString::operator==(const gString str)
{
	gString pt(ptr);
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

boolean gString::operator>=(gString str)
{
	gString st(ptr);
	return ((st > str) || (st == str)) ? TRUE : FALSE;
}

boolean gString::operator<=(gString str)
{
	gString st(ptr);
	return ((st < str) || (st == str)) ? TRUE : FALSE;
}

boolean gString::operator>(gString str)
{
	int lnstr = Length(str);
	int lnptr = Length(*this);
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

boolean gString::operator<(gString str)
{
	int lnstr = Length(str);
	int lnptr = Length(*this);
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

boolean gString::operator!=(const gString str)
{
	return (ptr == str.ptr) ? FALSE : TRUE;
}

gString gString::operator+(const gString str)
{
	int lnstr = Length(str);
	int lnptr = Length(*this);
	int i = 0, j = 0;	
	gString st(lnstr + lnptr);

	for(; i < lnptr; ++i)
		st.ptr[i] = ptr[i];
	for(; j < lnstr ; ++i , ++j)
		st.ptr[i] = str.ptr[j];
	
	st.ptr[lnstr + lnptr] = '\0';

	return st;
}

void gString::operator+=(const gString str)
{
	gString pt(ptr);
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

void gString::operator=(const gString str)
{
	if (&str == this)
		return;
	
	int ln = Length(str);

	ptr = new char[ln + 1];

	StrCpy(ptr,str.ptr);
	length = Length(str);
}

gString SubgString(const gString st,int from, int to)
{
	int ln = Length(st);
	int i,j = 0;

	gString temp(to);

	for(i = (from - 1) ; i < (from + to)  && i < ln; ++i)
	{
		temp.ptr[j] = st.ptr[i];
		++j;
	}

	temp.ptr[to] = '\0';
	
	return temp;
}


gString Left(const gString st, int l)
{
	int i;
	gString temp(l);

	for(i = 0 ; i < l ; ++i )
		temp.ptr[i] = st.ptr[i];

	temp.ptr[l] = '\0';

	return temp;
}

gString Right(const gString st, int r)
{
	int ln = Length(st);
	int i,j;
	gString temp(r);

	for(i = ln - 1, j = r - 1 ; i >= 0 && j >= 0 ; --i , --j)
		temp.ptr[j] = st.ptr[i];

	temp.ptr[r] = '\0';

	return temp;
}

gString Reverse(const gString st)
{
	int ln = Length(st);
	int i,j;

	gString temp(ln);

	for(i = (ln - 1) , j = 0; i >= 0 && j < ln; --i , ++j)
		temp.ptr[j] = st.ptr[i];

	temp.ptr[ln] = '\0';

	return temp;
}

gString Rtrim(const gString st)
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
		gString temp(pos + 1);

		for(i = 0; i <= pos ; ++i)
			temp.ptr[i] = st.ptr[i];
		
		temp.ptr[pos + 1] = '\0';		
		
		return temp;
	}
}


gString Ltrim(const gString st)
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
		gString temp(ln - pos);
		for(i = pos ; i < ln ; ++i)
			temp.ptr[i - pos] = st.ptr[i];

		temp.ptr[ln  - pos] = '\0';

		return temp;
	}
}

gString Alltrim(const gString st)
{
	gString temp(st);

	temp = Ltrim(temp);
	temp = Rtrim(temp);

	return temp;
}

gString ToLower(const gString st)
{
	int ln = Length(st);
	gString temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(temp.ptr[i] >= 65 && temp.ptr[i] < 91)
			temp.ptr[i] += 32;
	}

	return temp;
}

gString ToUpper(const gString st)
{
	int ln = Length(st);
	gString temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(temp.ptr[i] > 96 && temp.ptr[i] < 123)
			temp.ptr[i] -= 32;
	}

	return temp;
}

gString Proper(const gString st)
{
	int ln = Length(st);
	int check = 1;
	gString temp(ln);

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

gString Stuff(const gString st, char c)
{
	int ln = Length(st);
	gString temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
		if(temp.ptr[i] == ' ')
			temp.ptr[i] = c;
	return temp;
}


gString Replace(const gString str, const gString st,const gString s)
{
	int lnstr = Length(str);
	int lnst  = Length(st);
	int lns   = Length(s);
    	int replacepos = FindPos(str, st);
    	int lntemp;
	int i,j;

	if(lns != lnst)
	{
		cout << "Invalid gString Entry : gStrings Should Be of Equal Length";
		return str;
	}
	lntemp = lnstr - lnst + lns;

	gString temp(lntemp + 1);
    
	if(replacepos == -1)
	{
		cout << "gString not found";
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

gString Insert(const gString str, const gString st, int pos)
{
	int lnstr = Length(str);
	int lnst  = Length(st);
	int i,j;
	int lntemp = lnstr + lnst; 

	gString temp(lntemp + 1);

	for( i = 0; i < pos ; ++i)
		temp.ptr[i] = str.ptr[i];
	for( j = 0; j < lnst ; ++i, ++j)
		temp.ptr[i] = st.ptr[j];
	for(j = pos ; j < lnstr ; ++j , ++i)
		temp.ptr[i] = str.ptr[j];

	temp.ptr[lntemp] = '\0';

	return temp;
}

gString Remove(const gString str, const gString st)
{
	int lnstr = Length(str);
	int lnst  = Length(st);
	int removepos = FindPos(str, st);
	int i,j;
	int lntemp = lnstr - lnst; 

	gString temp(lntemp);

	if(removepos == -1)
	{
		cout << "gString not found";
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

gString Lshift(const gString st, int no)
{
	int lnstr = Length(st);
	
	if((no < 0) || (no > lnstr))
	{
		cout << "Lshift Not Possible";
		return st;
	}
	
	gString temp(lnstr + 1);

	for(int i = lnstr ; i >= no ; --i)
		temp.ptr[i - no] = st.ptr[i];

	temp.ptr[lnstr - no] = '\0';
	
	return temp;
}

gString Rshift(const gString st, int no)
{
	int lnstr = Length(st);
	
	if((no < 0) || (no > lnstr))
	{
		cout << "Rshift Not Possible";
		return st;
	}

	gString temp(lnstr - no);

	for(int i = 0 ; i < lnstr - no ; ++i)
		temp.ptr[i] = st.ptr[i];

	temp.ptr[lnstr - no] = '\0';
	
	return temp;
}

boolean Palindrome(const gString st)
{
	int lnstr = Length(st);
	gString temp(lnstr);

	temp = Reverse(st);

	return ((temp == st) ? TRUE : FALSE);
}

boolean Find(const gString str, const gString st)
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

boolean IsUpper(const gString st, int upto)
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

boolean IsLower(const gString st, int upto)
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

boolean IsAlpha(const gString st, int upto)
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


boolean IsNum(const gString st, int upto)
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

int Length(const gString& st)
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

int FindPos(const gString str, const gString st)
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

char Charat(const gString st, int pos)
{
	int lnstr = Length(st);
	return (pos >= 0 && pos < lnstr) ? st.ptr[pos - 1] : 'N';
}

double DouValue(const gString st)
{
	int lnstr = Length(st);
	int check = 0;
	
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
		/*	if(check != 1)
				num = num * 10 + Int(st.ptr[i]);
			else
			{	
				dec = dec + Int(st.ptr[i]);					
				dec /= 10;
			}*/
		}
	}
	else
		cout << "Non Numeric data Type";

	cout << "dec = " << dec;
	return (num + dec);

}

int IntValue(const gString st)
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
			
			//num = num * 10 + Int(st.ptr[i]);
		}
	}
	else
		cout << "Non Numeric data Type";

	return num;
}

int Int(const char c)
{
	return (c >= '0' || c <= '9') ? c - '0' : 0;
}
