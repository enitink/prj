#include<string.h>
#include<iostream.h>
//#include<conio.h>

enum boolean{FALSE,TRUE};

//BEGINING OF THE STRING CLASS
class String
{
	private :
		char *ptr;
		int length;

	public :

		String();
		String(int );
		String(char *n);
		String(const String &);
		~String();

		void showdata()
		{
			cout << endl << "#################################################################";
			cout << endl << "string :" << ptr;
			cout << endl << "length :" << length;			
		}

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



//	friend

	//friend 
	
	friend String SubString(const String mainstr, int from, int to);   /*To get Substring from the String */

	friend String Left(const String mainstr, int noofterms);			  /*To get required no. of characters from left side of String */

	friend String Right(const String mainstr, int noofterms);		  /*To get required no. of characters from right side of String */

	friend String Reverse(const String mainstr);               /*To reverse the given String */

	friend String Rtrim(const String mainstr);                 /*To remove right side trailing blank from the String */

	friend String Ltrim(const String mainstr);                 /*To remove left side leading blank from the String */

	friend String Alltrim(const String mainstr);               /*To remove all trailing and leading blank */

	friend String ToLower(const String mainstr);				  /*To convert all String characters into lower case */

	friend String ToUpper(const String mainstr);				  /*To convert all String characters into upper case */

	friend String Proper(const String mainstr);				  /*To convert all String characters into proper case */

	friend String Stuff(const String mainstr, char tofill);	  /*To fill the given char at blank spaces in a String */

	friend String Replace(const String mainstr,const   String thisstr,const   String withstr);  /* To Replace characters with other ones in the String*/

	friend String Insert(const String mainstr,const   String thisstr,  int at);           /*To insert required String in main String at any place*/

	friend String Remove(const String mainstr, const  String thisstr);       /*To remove required String from the main String*/

	friend String Lshift(const String mainstr, int noofpos) ;		  /*To left shift String Characters by required no. of places */

	friend String Rshift(const String mainstr, int noofpos);			  /*To right shift String Characters by required no. of places */

	friend boolean Palindrome(const String mainstr);					  /*To find whether a String is palindrome or not*/

	friend boolean Find(const String mainstr,const  String thisstr);		  /*To find the specified String in the main String*/

	friend boolean IsUpper(const String mainstr, int upto);			  /*To find whether the first Char of the String is in upper case or not*/

	friend boolean IsLower(const String mainstr, int upto);			  /*To find whether the first Char of the String is in lower case or not*/

	friend boolean IsAlpha(const String mainstr, int upto);			  /*To check the first char is a alphabet or not*/

	friend boolean IsNum(const String mainstr, int upto);			  /*To check the first char is a number or not*/

	friend int Length(const String mainstr);							  /*To find the Length of the String*/

	friend int FindPos(const String mainstr,const  String ofstr);            /*To find the position of the String in main String*/

	friend char Charat(const String mainstr, int pos);				  /*To get the char at the given place in the String*/

	friend double DouValue(const String mainstr);						  /*To convert the value of String into double Variable*/

	friend int IntValue(const String maintstr);
};
//END OF THE CLASS

String :: String()
{   
	ptr = new  char [100];
    length = 100;
}

String :: String(int l)
{
	ptr = new char[l + 1];
	length = l;
}

String :: String(char *str)
{
	length = strlen(str);
	ptr = new char[length + 1];
	strcpy(ptr, str);	
}

String :: String(const String &str)
{
	length = str.length;
	ptr = new char[length + 1];
	strcpy(ptr, str.ptr);
}

String :: ~String()
{
   delete [] ptr;
}

boolean String :: operator==(const String str)
{
	String st(str),pt(ptr);
	int lnstr = Length(st);
	int lnptr = Length(pt);
	int check = 1;

	if(lnstr == lnptr)
		for(int i = 0; i < lnstr ; ++i)
			check *= ((*(st.ptr + i) == *(pt.ptr + i)) ? 1 : 0);

	return  (check == 1) ? TRUE : FALSE;
}

/*boolean String :: operator>=(String str)
{

}

boolean String :: operator<=(String str)
{

}

boolean String :: operator>(String str)
{

}

boolean String :: operator<(String str)
{

}*/

boolean String :: operator!=(const String str)
{
	String st(str),pt(ptr);
	return (pt == st.ptr) ? FALSE : TRUE;
}

String String :: operator+(const String str)
{
	String str1(str),pt(ptr);
	int lnstr = Length(str1);
	int lnptr = Length(pt);
	String st(lnstr + lnptr);

	st.ptr = pt.ptr;

	for(int i = lnptr; i < lnstr ; ++i)
		*(st.ptr + i) = *(str1.ptr + i - lnptr);

	return st;
}

void String ::operator+=(const String str)
{
	String str1(str),pt(ptr);
	int lnstr = Length(str1);
	int lnptr = Length(pt);
	int i;

	for(i = 0 ; i < lnptr ; ++i)
		*(ptr + i) = *(pt.ptr + i - lnptr);
	for(          ; i < lnptr + lnstr; ++i)
		*(ptr + i) = *(str1.ptr + i - lnptr);
}

void String :: operator=(const String str)
{
	String st(str);
	strcpy(ptr,st.ptr);
	length = strlen(st.ptr);
}

String SubString(const String str, int from, int to)
{
	String st(str);
	int ln = Length(st);
	int i,j = 0;

	String temp(to + 1);

	for(i = (from - 1) ; i < (from + to - 1)  && i < ln; ++i)
	{
		*(temp.ptr + j) = *(st.ptr + i);
		++j;
	}

	*(temp.ptr + j) = '\0';

	return temp;
}


String Left(const String str, int l)
{
	String st(str);
	//int ln = Length(st);
	int i;
	String temp(l);

	for(i = 0 ; i < l ; ++i )
		*(temp.ptr + i) = *(st.ptr + i);

	*(temp.ptr + l) = '\0';

	return temp;

}

String Right(const String str, int r)
{
	String st(str);
	int ln = Length(st);
	int i,j;
	String temp(r);

	for(i = ln - 1, j = r - 1 ; i >= 0 && j >= 0 ; --i , --j)
		*(temp.ptr + j) = *(st.ptr + i);

	*(temp.ptr + r) = '\0';

	return temp;
}

String Reverse(const String str)
{
	String st(str);
	int ln = Length(st);
	int i,j;

	String temp(ln);

	for(i = (ln - 1) , j = 0; i >= 0 && j < ln; --i , ++j)
		*(temp.ptr + j) = *(st.ptr + i);

	*(temp.ptr + ln) = '\0';

	return temp;
}

String Rtrim(const String str)
{
	String st(str);
	int ln = Length(st);
	int i;
	int pos = ln - 1;
	int count = 0;

	for(i = ln - 1; i >= 0; --i)
		if(*(st.ptr + i) != ' ' && pos == ln - 1 && count == 0)
		{
			pos = i + 1;
			count++;
		}

	if(pos == ln - 1)
		return st;
	else
	{
		String temp(pos + 1);

		for(i = 0; i <= pos || i < ln; ++i)
			  *(temp.ptr + i) = *(st.ptr + i);

		*(temp.ptr + pos + 1) = '\0';

		return temp;
	}
}


String Ltrim(const String str)
{
	String st(str);
	int ln = Length(st);
	int i;
	int pos = 0;
	int count = 0;

	for(i = 0; i < ln ; ++i)
		if(*(st.ptr + i) != ' ' && pos == 0 && count == 0)
		{
			count++;
			pos = i;
		}

	if(pos == 0)
		return st;
	else
	{
		String temp(ln - pos + 1);
		for(i = pos ; i < ln ; ++i)
			*(temp.ptr + i - pos) = *(st.ptr + i);

		*(temp.ptr + ln  - pos ) = '\0';

		return temp;
	}
}

String Alltrim(const String str)
{
	String temp(str);

	temp = Ltrim(temp);
	temp = Rtrim(temp);

	return temp;
}

String ToLower(const String str)
{
	String st(Alltrim(str));
	int ln = Length(st);
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(*(temp.ptr + i) >= 65 && *(temp.ptr + i) < 91)
			*(temp.ptr + i) += 32;
	}

	return temp;
}

String ToUpper(const String str)
{
	String st(str);
	int ln = Length(st);
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
	{
		if(*(temp.ptr + i) > 96 && *(temp.ptr + i) < 123)
			*(temp.ptr + i) -= 32;
	}

	return temp;
}

String Proper(const String str)
{
	String st(str);
	int ln = Length(st);
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

String Stuff(const String str, char c)
{
	String st(str);
	int ln = Length(st);
	String temp(ln);

	temp = st;

	for(int i = 0; i < ln; ++i)
		if(*(temp.ptr + i) == ' ')
			*(temp.ptr + i) = c;
	return temp;
}


String Replace(const String str,const String st,const String s)
{
	String str1(str),st1(st),s1(s);
	
	int lnstr = Length(str1);
	int lnst  = Length(st1);
	int lns   = Length(s1);
    int replacepos = FindPos(str1,st1);
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
			*(temp.ptr + i) = *(str1.ptr + i);
		for( j = 0 ; j < lns ; ++i , ++j)
			*(temp.ptr + i) = *(s1.ptr + j);
		for(j = replacepos + lns - 1; j < lnstr && i < lntemp; ++j , ++i)
			*(temp.ptr + i) = *(str1.ptr + j);


        *(temp.ptr + lntemp) = '\0';
		
		return temp;
	}
}

String Insert(const String str,const String st, int pos)
{
	String str1(str),st1(st);
	int lnstr = Length(str1);
	int lnst  = Length(st1);
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

String Remove(const String str, const String st)
{
	String str1(str),st1(st);
	int lnstr = Length(str1);
	int lnst  = Length(st1);
	int removepos = FindPos(str1,st1);
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
			*(temp.ptr + i) = *(str1.ptr + i);
		for(j = removepos + lnst - 1; j < lnstr ; ++i , ++j)
			*(temp.ptr + i) = *(str1.ptr + j);
		
		*(temp.ptr + lntemp) = '\0';

		return temp;
	}
}

String Lshift(const String str, int no)
{
	String st(str);
	int lnstr = Length(st);
	
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

String Rshift(const String str,  int no)
{
	String st(str);
	int lnstr = Length(st);
	
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

boolean Palindrome(const String str)
{
	String st(str);
	int lnstr = Length(st);
	String temp(lnstr);

	temp = Reverse(st);

	return ((temp == st) ? TRUE : FALSE);
}

boolean Find(const String str, const String st)
{
	String str1(str),st1(st);
	int lnstr = Length(str1);
	int lnst = Length(st1);
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

boolean IsUpper(const String str, int upto)
{
	String st(str);
	int lnstr = Length(st);
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(*(st.ptr + i) != ' ')
			check *= ((*(st.ptr + i) >= 65 &&  *(st.ptr + i) < 91) ? 1 : 0);
		else
			check *= 1;
	}
		
	return (check == 1) ? TRUE : FALSE;
}

boolean IsLower(const String str, int upto)
{
	String st(str);
	int lnstr = Length(st);
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(*(st.ptr + i) != ' ')
			check *= ((*(st.ptr + i) > 96 &&  *(st.ptr + i) < 123) ? 1 : 0);
		else
			check *= 1;
	}

	return (check == 1) ? TRUE : FALSE;
}

boolean IsAlpha(const String str, int upto)
{
	String st(str);
	int lnstr = Length(st);
	int check = 1;

	for(int i = 0; i < upto && i < lnstr ; ++i)
	{
		if(*(st.ptr + i) != ' ')
			check *= (((*(st.ptr + i) > 96 &&  *(st.ptr + i) < 123)
						|| ((*(st.ptr + i) >= 65 &&  *(st.ptr + i) < 91)) ? 1 : 0));
		else
			check *= 1;
	}

	return (check == 1) ? TRUE : FALSE;
}


boolean IsNum(const String str, int upto)
{
	String st(str);
	int lnstr = Length(st);
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
	}

	return (check == 1) ? TRUE : FALSE;
}

int Length(const String str)
{
	int i = 0;
	int len = 0;

	while(*(str.ptr + i) != '\0')
	{
		++i;
		++len;
	}
	return (len);
}

int FindPos(const String str,const String st)
{
	String str1(str),st1(st);
	int lnstr = Length(str1);
	int lnst = Length(st1);
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

char Charat(const String str, int pos)
{
	String st(str);
	int lnstr = Length(st);
	return ((pos >= 0 && pos < lnstr) ? *(st.ptr + pos - 1) : 'N');
}

double DouValue(const String str)
{
	String st(str);
	int lnstr = Length(st);
	int check = 0;
	double num = 0;

	if(IsNum(str,lnstr))
	{
		for(int i = 0 ; i < lnstr ; ++i)
		{
			if(*(st.ptr + i) == '.')
				check = 1;
			if(check != 1)
				num = num * 10 + double(*(st.ptr + i));
			else
				num = num + (double(*st.ptr + i)) / 10;
		}
	}
	else
		cout << "Non Numeric data Type";

	return num;
}



void main()
{
	String ob("i am nItin");
	String obj;
	String ob1("111111.11");
	String ob2("ni");

	ob1.showdata();

	cout << "enter a string";
	cin >> obj;

	obj.showdata();


	//getch();
}



