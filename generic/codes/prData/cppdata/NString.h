#ifndef NSTRING_H
#define NSTRING_H

enum boolean{FALSE,TRUE};

int StrLen(char *ptr);
void StrCpy(char *ptr, char *str);

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
	boolean operator==(const String);
	boolean operator>=(const String);
	boolean operator<=(const String);
	boolean operator>(const String);
	boolean operator<(const String);
	boolean operator!=(const String);
	String operator+(const String);				  /* To concatenate two strings */
	void operator+=(const String);
	void operator=(const String);

	friend int Int(const char);
	
	friend ostream &operator<<( ostream &, const String & );
	
	friend istream &operator>>( istream &, String & );
	
	friend String SubString(const String, int from, int to);   /*To get Substring from the String */

	friend String Left(const String, int noofterms);			  /*To get required no. of characters from left side of String */

	friend String Right(const String, int noofterms);		  /*To get required no. of characters from right side of String */

	friend String Reverse(const String);               /*To reverse the given String */

	friend String Rtrim(const String);                 /*To remove right side trailing blank from the String */

	friend String Ltrim(const String);                 /*To remove left side leading blank from the String */

	friend String Alltrim(const String);               /*To remove all trailing and leading blank */

	friend String ToLower(const String);				  /*To convert all String characters into lower case */

	friend String ToUpper(const String);				  /*To convert all String characters into upper case */

	friend String Proper(const String);				  /*To convert all String characters into proper case */

	friend String Stuff(const String, char tofill);	  /*To fill the given char at blank spaces in a String */

	friend String Replace(const String mainstr, const String thisstr,const   String withstr);  /* To Replace characters with other ones in the String*/

	friend String Insert(const String mainstr,const String thisstr,  int at);           /*To insert required String in main String at any place*/

	friend String Remove(const String mainstr, const  String thisstr);       /*To remove required String from the main String*/

	friend String Lshift(const String, int noofpos) ;		  /*To left shift String Characters by required no. of places */

	friend String Rshift(const String, int noofpos);			  /*To right shift String Characters by required no. of places */

	friend boolean Palindrome(const String);					  /*To find whether a String is palindrome or not*/

	friend boolean Find(const String mainstr, const String thisstr);		  /*To find the specified String in the main String*/

	friend boolean IsUpper(const String, int upto);			  /*To find whether the first Char of the String is in upper case or not*/

	friend boolean IsLower(const String, int upto);			  /*To find whether the first Char of the String is in lower case or not*/

	friend boolean IsAlpha(const String, int upto);			  /*To check the first char is a alphabet or not*/

	friend boolean IsNum(const String, int upto);			  /*To check the first char is a number or not*/

	friend int Length(const String);							  /*To find the Length of the String*/

	friend int FindPos(const String mainstr, const  String ofstr);            /*To find the position of the String in main String*/

	friend char Charat(const String, int pos);				  /*To get the char at the given place in the String*/

	friend double DouValue(const String);						  /*To convert the value of String into double Variable*/

	friend int IntValue(const String);	
};
//END OF THE CLASS

#endif

