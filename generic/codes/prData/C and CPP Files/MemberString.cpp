#include<iostream.h>

enum boolean{FALSE,TRUE};

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
	
	for(int i = 0; i < ln ; ++i)
		*(ptr + i) = *(str + i);

    *(ptr + i) = '\0';
}

//BEGINING OF THE STRING CLASS
class String
{
	
	friend ostream &operator<<( ostream &, const String & );
	friend istream &operator>>( istream &, String & );
	
	private :
		char *ptr;
		int length;

	public :

		String();
		String(int );
		String(char *n);
		String(const String &);
		~String();
		
// OPERATORS

		boolean operator==(const String);

		boolean operator>=(const String);

		boolean operator<=(const String);

		boolean operator>(const String);

		boolean operator<(const String);

		boolean operator!=(const String);

		String operator+(const String);				  /* To concatenate two strings */

		void operator+=(const String);

		void operator=(const String);



//	Member function

	//
	
		String SubString(int from, int to);   /*To get Substring from the String */

		String Left(int noofterms);			  /*To get required no. of characters from left side of String */

		String Right(int noofterms);		  /*To get required no. of characters from right side of String */

		String Reverse();               /*To reverse the given String */

		String Rtrim();                 /*To remove right side trailing blank from the String */

		String Ltrim();                 /*To remove left side leading blank from the String */

		String Alltrim();               /*To remove all trailing and leading blank */

		String ToLower();				  /*To convert all String characters into lower case */

		String ToUpper();				  /*To convert all String characters into upper case */

		String Proper();				  /*To convert all String characters into proper case */

		String Stuff(char tofill);	  /*To fill the given char at blank spaces in a String */

		String Replace(const String thisstr,const   String withstr);  /* To Replace characters with other ones in the String*/

		String Insert(const String thisstr,  int at);           /*To insert required String in main String at any place*/

		String Remove( const  String thisstr);       /*To remove required String from the main String*/

		String Lshift( int noofpos) ;		  /*To left shift String Characters by required no. of places */

		String Rshift( int noofpos);			  /*To right shift String Characters by required no. of places */

		boolean Palindrome();					  /*To find whether a String is palindrome or not*/

		boolean Find(const  String thisstr);		  /*To find the specified String in the main String*/

		boolean IsUpper( int upto);			  /*To find whether the first Char of the String is in upper case or not*/

		boolean IsLower( int upto);			  /*To find whether the first Char of the String is in lower case or not*/

		boolean IsAlpha( int upto);			  /*To check the first char is a alphabet or not*/

		boolean IsNum( int upto);			  /*To check the first char is a number or not*/

		int Length();							  /*To find the Length of the String*/

		int FindPos(const  String ofstr);            /*To find the position of the String in main String*/

		char Charat(int pos);				  /*To get the char at the given place in the String*/

		double DouValue();						  /*To convert the value of String into double Variable*/

		int IntValue();

		int Int(int pos);	

};
//END OF THE CLASS


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

boolean  String :: operator==(const String str)
{
	String st(str),pt(ptr);
	int lnstr = st.Length();
	int lnptr = pt.Length();
	int check = 1;

	if(lnstr == lnptr)
		for(int i = 0; i < lnstr ; ++i)
			check *= ((*(st.ptr + i) == *(pt.ptr + i)) ? 1 : 0);
	else
		check = 0;

	return  (check == 1) ? TRUE : FALSE;
}

boolean String :: operator>=(String str)
{
	String st(ptr);
	return ((st > str) || (st == str)) ? TRUE : FALSE;
}

boolean  String :: operator<=(String str)
{
	String st(ptr);
	return ((st < str) || (st == str)) ? TRUE : FALSE;
}

boolean  String :: operator>(String str)
{
	String st(str),pt(ptr);
	int lnstr = st.Length();
	int lnptr = pt.Length();
	int check = 1;
	int min = lnptr;

	if(lnstr < lnptr)
		min = lnstr;
	
	for(int i = 0; i < min ; ++i)
	{
		if(*(ptr + i) > *(st.ptr + i))
		{
			check = 1;
			break;
		}
		else
		{	
			if(*(ptr + i) == *(st.ptr + i))
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

boolean  String :: operator<(String str)
{
	String st(str),pt(ptr);
	int lnstr = st.Length();
	int lnptr = pt.Length();
	int check = 1;
	int min = lnptr;

	if(lnstr < lnptr)
		min = lnstr;
	
	for(int i = 0; i < min ; ++i)
	{
		if(*(ptr + i) < *(st.ptr + i))
		{
			check = 1;
			break;
		}
		else
		{	
			if(*(ptr + i) == *(st.ptr + i))
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

boolean  String :: operator!=(const String str)
{
	String st(str),pt(ptr);
	return (pt == st.ptr) ? FALSE : TRUE;
}

String String :: operator+(const String str)
{
	String str1(str),pt(ptr);
	int lnstr = str1.Length();
	int lnptr = pt.Length();
	
	String st(lnstr + lnptr);

	for(int i = 0; i < lnptr; ++i)
		*(st.ptr + i) = *(pt.ptr + i);
	for(int j = 0; j < lnstr ; ++i , ++j)
		*(st.ptr + i) = *(str1.ptr + j);
	
	*(st.ptr + lnstr + lnptr) = '\0';

	return st;
}

void String ::operator+=(const String str)
{
	String str1(str),pt(ptr);
	int lnstr = str1.Length();
	int lnptr = pt.Length();
	int i,j;
	
	ptr = new char[lnstr + lnptr + 1];

	for(i = 0 ; i < lnptr ; ++i)
		*(ptr + i) = *(pt.ptr + i);
	for(j = 0 ; j < lnstr; ++i, ++j)
		*(ptr + i) = *(str1.ptr + j);
	
	*(ptr + i) = '\0';

}

void String :: operator=(const String str)
{
	String st(str);
	int ln = st.Length();

	ptr = new char[ln + 1];

	StrCpy(ptr,st.ptr);
	length = st.Length();
}

String String :: SubString( int from, int to)
{
	String st(ptr);
	int ln = st.Length();
	int i,j = 0;

	String temp(to);

	for(i = (from - 1) ; i < (from + to)  && i < ln; ++i)
	{
		*(temp.ptr + j) = *(st.ptr + i);
		++j;
	}

	*(temp.ptr + to) = '\0';
	
	return temp;
}


String String :: Left( int l)
{
	String st(ptr);
	int i;
	String temp(l);

	for(i = 0 ; i < l ; ++i )
		*(temp.ptr + i) = *(st.ptr + i);

	*(temp.ptr + l) = '\0';

	return temp;
}

String String :: Right( int r)
{
	String st(ptr);
	int ln = st.Length();
	int i,j;
	String temp(r);

	for(i = ln - 1, j = r - 1 ; i >= 0 && j >= 0 ; --i , --j)
		*(temp.ptr + j) = *(st.ptr + i);

	*(temp.ptr + r) = '\0';

	return temp;
}

String String :: Reverse()
{
	String st(ptr);
	int ln = st.Length();
	int i,j;

	String temp(ln);

	for(i = (ln - 1) , j = 0; i >= 0 && j < ln; --i , ++j)
		*(temp.ptr + j) = *(st.ptr + i);

	*(temp.ptr + ln) = '\0';

	return temp;
}

String String :: Rtrim()
{
	String st(ptr);
	int ln = st.Length();
	int i;
	int pos = 0;
	
	for(i = ln - 1; i >= 0; --i)
		if(*(st.ptr + i) != ' ')
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
			*(temp.ptr + i) = *(st.ptr + i);
		
		*(temp.ptr + pos + 1) = '\0';		
		
		return temp;
	}
}


String String :: Ltrim()
{
	String st(ptr);
	int ln = st.Length();
	int i;
	int pos = 0;
	
	for(i = 0; i < ln ; ++i)
		if(*(st.ptr + i) != ' ')
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
			*(temp.ptr + i - pos) = *(st.ptr + i);

		*(temp.ptr + ln  - pos ) = '\0';

		return temp;
	}
}

String String :: Alltrim()
{
	String temp(ptr);

	temp = temp.Ltrim();
	temp = temp.Rtrim();

	return temp;
}

String String :: ToLower()
{
	String st(ptr);
	int ln = st.Length();
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(*(temp.ptr + i) >= 65 && *(temp.ptr + i) < 91)
			*(temp.ptr + i) += 32;
	}

	return temp;
}

String String :: ToUpper()
{
	String st(ptr);
	int ln = st.Length();
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(*(temp.ptr + i) > 96 && *(temp.ptr + i) < 123)
			*(temp.ptr + i) -= 32;
	}

	return temp;
}

String String :: Proper()
{
	String st(ptr);
	int ln = st.Length();
	int check = 1;
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(check == 1)
			*(temp.ptr + i) = (*(temp.ptr + i) > 96 && *(temp.ptr + i) < 123 ?
								 (*(temp.ptr + i) -32) : (*(temp.ptr + i)));
		else
			*(temp.ptr + i) = (*(temp.ptr + i) >= 65 && *(temp.ptr + i) < 91 ?
								 (*(temp.ptr + i) + 32) : (*(temp.ptr + i)));

		if(*(temp.ptr + i) == ' ')
			check = 1;
		else
			check = 0;

	}

	return temp;
}

String String :: Stuff( char c)
{
	String st(ptr);
	int ln = st.Length();
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
		if(*(temp.ptr + i) == ' ')
			*(temp.ptr + i) = c;
	return temp;
}


String String :: Replace(const String st,const String s)
{
	String str1(ptr),st1(st),s1(s);
	
	int lnstr = str1.Length();
	int lnst  = st1.Length();
	int lns   = s1.Length();
    int replacepos = str1.FindPos(st1);
    int lntemp;
	int i,j;

	if(lns != lnst)
	{
		cout << "Invalid String Entry : Strings Should Be of Equal Length";
		return ptr;
	}
	lntemp = lnstr - lnst + lns;

	String temp(lntemp + 1);
    
	if(replacepos == -1)
	{
		cout << "String not found";
		return ptr;
	}
	else
	{
		for( i = 0 ; i < replacepos - 1 ; ++i)
			*(temp.ptr + i) = *(str1.ptr + i);
		for( j = 0 ; j < lns ; ++i , ++j)
			*(temp.ptr + i) = *(s1.ptr + j);
		for(j = replacepos + lns - 1; j < lnstr && i < lntemp; ++j , ++i)
			*(temp.ptr + i) = *(str1.ptr + j);


        *(temp.ptr + lntemp) = '\0';
		
		return temp;
	}
}

String String :: Insert(const String st, int pos)
{
	String str1(ptr),st1(st);
	int lnstr = str1.Length();
	int lnst  = st1.Length();
	int i,j;
	int lntemp = lnstr + lnst; 

	String temp(lntemp + 1);

	for( i = 0; i < pos ; ++i)
		*(temp.ptr + i) = *(str1.ptr + i);
	for( j = 0; j < lnst ; ++i, ++j)
		*(temp.ptr + i) = *(st1.ptr + j);
	for(j = pos ; j < lnstr ; ++j , ++i)
		*(temp.ptr + i) = *(str1.ptr + j);

	*(temp.ptr + lntemp) = '\0';

	return temp;
}

String String :: Remove( const String st)
{
	String str1(ptr),st1(st);
	int lnstr = str1.Length();
	int lnst  = st1.Length();
	int removepos = str1.FindPos(st1);
    int i,j;
	int lntemp = lnstr - lnst; 

	String temp(lntemp);

	if(removepos == -1)
	{
		cout << "String not found";
		return ptr;
	}
	else
	{
		for(i = 0 ; i < removepos - 1; ++i)
			*(temp.ptr + i) = *(str1.ptr + i);
		for(j = removepos + lnst - 1; j < lnstr ; ++i , ++j)
			*(temp.ptr + i) = *(str1.ptr + j);
		
		*(temp.ptr + lntemp) = '\0';

		return temp;
	}
}

String String :: Lshift( int no)
{
	String st(ptr);
	int lnstr = st.Length();
	
	if((no < 0) || (no > lnstr))
	{
		cout << "Lshift Not Possible";
		return st;
	}
	
	String temp(lnstr + 1);

	for(int i = lnstr ; i >= no ; --i)
		*(temp.ptr + i - no) = *(st.ptr + i);

	*(temp.ptr + lnstr - no) = '\0';
	
	return temp;
}

String String :: Rshift(  int no)
{
	String st(ptr);
	int lnstr = st.Length();
	
	if((no < 0) || (no > lnstr))
	{
		cout << "Rshift Not Possible";
		return st;
	}

	String temp(lnstr - no);

	for(int i = 0 ; i < lnstr - no ; ++i)
		*(temp.ptr + i) = *(st.ptr + i);

	*(temp.ptr + lnstr - no) = '\0';
	
	return temp;
}

boolean String :: Palindrome()
{
	String st(ptr);
	int lnstr = st.Length();
	String temp(lnstr);

	temp = st.Reverse();

	return ((temp == st) ? TRUE : FALSE);
}

boolean String :: Find( const String st)
{
	String str1(ptr),st1(st);
	int lnstr = str1.Length();
	int lnst = st1.Length();
	int check = 1;

	for(int i = 0; i < lnstr ; ++i)
	{ 
		check = 1;
		for(int j = 0; j < lnst; ++j)
			check *= ((*(str1.ptr + i + j) == *(st1.ptr + j)) ? 1 : 0);
		
		if(check == 1) 
			return TRUE;
		else
			continue;
	}		

	return FALSE;	
}

boolean String :: IsUpper( int upto)
{
	String st(ptr);
	int lnstr = st.Length();
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(*(st.ptr + i) != ' ')
		{
			check *= ((*(st.ptr + i) >= 65 &&  *(st.ptr + i) < 91) ? 1 : 0);
			if(check == 0)
				break;
		}
		else
			check *= 1;
	}
		
	return (check == 1) ? TRUE : FALSE;
}

boolean String :: IsLower( int upto)
{
	String st(ptr);
	int lnstr = st.Length();
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(*(st.ptr + i) != ' ')
		{
			check *= ((*(st.ptr + i) > 96 &&  *(st.ptr + i) < 123) ? 1 : 0);
			if(check == 0)
				break;
		}
		else
			check *= 1;
	}

	return (check == 1) ? TRUE : FALSE;
}

boolean String :: IsAlpha( int upto)
{
	String st(ptr);
	int lnstr = st.Length();
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(*(st.ptr + i) != ' ')
		{
			check *= (((*(st.ptr + i) > 96 &&  *(st.ptr + i) < 123)
						|| ((*(st.ptr + i) >= 65 &&  *(st.ptr + i) < 91)) ? 1 : 0));
			if(check == 0)
				break;
		}
		else
			check *= 1;
	}

	return (check == 1) ? TRUE : FALSE;
}


boolean String :: IsNum( int upto)
{
	String st(ptr);
	int lnstr = st.Length();
	int check = 1;
	int ch = 0;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		check *=     (*(st.ptr + i) >= '0')
				  && (*(st.ptr + i) <= '9')
				  || (*(st.ptr + i) == '.') ? 1 : 0;
		if(*(st.ptr + i) == '.')
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

int String :: Length()
{
	int i = 0;
	int len = 0;

	while(*(ptr + i) != '\0')
	{
		++i;
		++len;
	}
	return (len);
}

int String :: FindPos(const String st)
{
	String str1(ptr),st1(st);
	int lnstr = str1.Length();
	int lnst = st1.Length();
	int check = 1;

	for(int i = 0; i < lnstr ; ++i)
	{ 
		check = 1;
		for(int j = 0; j < lnst; ++j)
			check *= ((*(str1.ptr + i + j) == *(st1.ptr + j)) ? 1 : 0);

		if(check == 1) 
			return i+1;
		else
			continue;
	}		

	return -1;
}					

char String ::  Charat( int pos)
{
	String st(ptr);
	int lnstr = st.Length();
	return ((pos >= 0 && pos < lnstr) ? *(st.ptr + pos - 1) : 'N');
}

double String :: DouValue()
{
	String st(ptr);
	int lnstr = st.Length();
	int check = 0;
	
	double num = 0;
	double dec = 0;

	if(st.IsNum(lnstr))
	{
		for(int i = 0 ; i < lnstr; ++i)
		{
			if(*(st.ptr + i) == '.')
			{
				check = 1;
				continue;
			}
			if(check != 1)
				num = num * 10 + st.Int(i);
			else
			{	
				dec = dec + st.Int(i);					
				dec /= 10;
			}

		}
	}
	else
		cout << "Non Numeric data Type";

	cout << "dec = " << dec;
	return (num + dec);

}

int String :: IntValue()
{
	String st(ptr);
	int lnstr = st.Length();
	int check = 0;
	
	int num = 0;
	
	if(st.IsNum(lnstr))
	{
		for(int i = 0 ; i < lnstr; ++i)
		{
			if(*(st.ptr + i) == '.')
			{
				cout << "Non Numeric data Type";
				return 0;		
			}
			
			num = num * 10 + st.Int(i);
		}
	}
	else
		cout << "Non Numeric data Type";

	return num;
}

int String :: Int(int pos)
{
	switch (*(ptr + pos))
	{
	case '0' :
		return 0;
	case '1' :
		return 1;
	case '2' :
		return 2;
	case '3' :
		return 3;
	case '4' :
		return 4;
	case '5' :
		return 5;
	case '6' :
		return 6;
	case '7' :
		return 7;
	case '8' :
		return 8;
	case '9' :
		return 9;
	}
	
	return 0;
}

int main()
{
	String ob(10),obj;
	String result;
	
	cout << "Enter Any String";
	cin >> ob;
	cout << "Enter second String";
	cin >> obj;

	cout << "double value" << ob.DouValue();

	return 0;
}