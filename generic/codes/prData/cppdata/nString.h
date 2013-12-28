#ifndef	_N_STRING_H 
#define _N_STRING_H

enum boolean{FALSE,TRUE};

int StrLen(char *ptr);
void StrCpy(char *ptr, char *str);

class nString
{	
private :
	char *ptr;
	int length;				
	
public :

	nString();
	nString(int );
	nString(char *n);
	nString(const nString &);
	~nString();
	boolean operator==(const nString);
	boolean operator>=(const nString);
	boolean operator<=(const nString);
	boolean operator>(const nString);
	boolean operator<(const nString);
	boolean operator!=(const nString);
	nString operator+(const nString);				  /* To concatenate two strings */
	void operator+=(const nString);
	void operator=(const nString);

	friend int Int(const char);
	
	friend ostream &operator<<( ostream &, const nString & );
	
	friend istream &operator>>( istream &, nString & );
	
	friend nString SubnString(const nString, int from, int to);   /*To get Substring from the nString */

	friend nString Left(const nString, int noofterms);			  /*To get required no. of characters from left side of nString */

	friend nString Right(const nString, int noofterms);		  /*To get required no. of characters from right side of nString */

	friend nString Reverse(const nString);               /*To reverse the given nString */

	friend nString Rtrim(const nString);                 /*To remove right side trailing blank from the nString */

	friend nString Ltrim(const nString);                 /*To remove left side leading blank from the nString */

	friend nString Alltrim(const nString);               /*To remove all trailing and leading blank */

	friend nString ToLower(const nString);				  /*To convert all nString characters into lower case */

	friend nString ToUpper(const nString);				  /*To convert all nString characters into upper case */

	friend nString Proper(const nString);				  /*To convert all nString characters into proper case */

	friend nString Stuff(const nString, char tofill);	  /*To fill the given char at blank spaces in a nString */

	friend nString Replace(const nString mainstr, const nString thisstr,const   nString withstr);  /* To Replace characters with other ones in the nString*/

	friend nString Insert(const nString mainstr,const nString thisstr,  int at);           /*To insert required nString in main nString at any place*/

	friend nString Remove(const nString mainstr, const  nString thisstr);       /*To remove required nString from the main nString*/

	friend nString Lshift(const nString, int noofpos) ;		  /*To left shift nString Characters by required no. of places */

	friend nString Rshift(const nString, int noofpos);			  /*To right shift nString Characters by required no. of places */

	friend boolean Palindrome(const nString);					  /*To find whether a nString is palindrome or not*/

	friend boolean Find(const nString mainstr, const nString thisstr);		  /*To find the specified nString in the main nString*/

	friend boolean IsUpper(const nString, int upto);			  /*To find whether the first Char of the nString is in upper case or not*/

	friend boolean IsLower(const nString, int upto);			  /*To find whether the first Char of the nString is in lower case or not*/

	friend boolean IsAlpha(const nString, int upto);			  /*To check the first char is a alphabet or not*/

	friend boolean IsNum(const nString, int upto);			  /*To check the first char is a number or not*/

	friend int Length(const nString);							  /*To find the Length of the nString*/

	friend int FindPos(const nString mainstr, const  nString ofstr);            /*To find the position of the nString in main nString*/

	friend char Charat(const nString, int pos);				  /*To get the char at the given place in the nString*/

	friend double DouValue(const nString);						  /*To convert the value of nString into double Variable*/

	friend int IntValue(const nString);	
};

#endif

