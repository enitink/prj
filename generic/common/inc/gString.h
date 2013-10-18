#ifndef NSTRING_H
#define NSTRING_H

enum boolean{FALSE,TRUE};

int StrLen(char *ptr);
void StrCpy(char *ptr, char *str);

//BEGINING OF THE STRING CLASS
class gString
{	
private :
	char *ptr;
	int length;

public :

	gString();
	gString(int );
	gString(char *n);
	gString(const gString &);
	~gString();
	boolean operator==(const gString);
	boolean operator>=(const gString);
	boolean operator<=(const gString);
	boolean operator>(const gString);
	boolean operator<(const gString);
	boolean operator!=(const gString);
	gString operator+(const gString);				/* To concatenate two strings */
	void 	operator+=(const gString);
	void 	operator=(const gString);

	friend int Int(const char);
	friend ostream &operator<<( ostream &, const gString & );
	friend istream &operator>>( istream &, gString & );
	friend gString SubgString(const gString, int from, int to);   /*To get Substring from the gString */
	friend gString Left(const gString, int noofterms);			  /*To get required no. of characters from left side of gString */
	friend gString Right(const gString, int noofterms);		  /*To get required no. of characters from right side of gString */
	friend gString Reverse(const gString);               /*To reverse the given gString */
	friend gString Rtrim(const gString);                 /*To remove right side trailing blank from the gString */
	friend gString Ltrim(const gString);                 /*To remove left side leading blank from the gString */
	friend gString Alltrim(const gString);               /*To remove all trailing and leading blank */
	friend gString ToLower(const gString);				  /*To convert all gString characters into lower case */
	friend gString ToUpper(const gString);				  /*To convert all gString characters into upper case */
	friend gString Proper(const gString);				  /*To convert all gString characters into proper case */
	friend gString Stuff(const gString, char tofill);	  /*To fill the given char at blank spaces in a gString */
	friend gString Replace(const gString mainstr, const gString thisstr,const   gString withstr);  /* To Replace characters with other ones in the gString*/
	friend gString Insert(const gString mainstr,const gString thisstr,  int at);           /*To insert required gString in main gString at any place*/
	friend gString Remove(const gString mainstr, const  gString thisstr);       /*To remove required gString from the main gString*/
	friend gString Lshift(const gString, int noofpos) ;		  /*To left shift gString Characters by required no. of places */
	friend gString Rshift(const gString, int noofpos);			  /*To right shift gString Characters by required no. of places */
	friend boolean Palindrome(const gString);					  /*To find whether a gString is palindrome or not*/
	friend boolean Find(const gString mainstr, const gString thisstr);		  /*To find the specified gString in the main gString*/
	friend boolean IsUpper(const gString, int upto);			  /*To find whether the first Char of the gString is in upper case or not*/
	friend boolean IsLower(const gString, int upto);			  /*To find whether the first Char of the gString is in lower case or not*/
	friend boolean IsAlpha(const gString, int upto);			  /*To check the first char is a alphabet or not*/
	friend boolean IsNum(const gString, int upto);			  /*To check the first char is a number or not*/
	friend int Length(const gString&);							  /*To find the Length of the gString*/
	friend int FindPos(const gString mainstr, const  gString ofstr);            /*To find the position of the gString in main gString*/
	friend char Charat(const gString, int pos);				  /*To get the char at the given place in the gString*/
	friend double DouValue(const gString);						  /*To convert the value of gString into double Variable*/
	friend int IntValue(const gString);	
};
//END OF THE CLASS

#endif
