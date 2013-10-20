#ifndef NSTRING_H
#define NSTRING_H

#include<iostream>

using std :: ostream;
using std :: istream;

enum boolean{FALSE,TRUE};

int StrLen(char *ptr);
void StrCpy(char *ptr, char *str);

//BEGINING OF THE STRING CLASS
class String
{	
	friend int Int(const char);	
	friend ostream &operator<<( ostream &, const String & );	
	friend istream &operator>>( istream &, String & );	
	friend String SubString(const String, int from, int to);	
	friend String Left(const String, int noofterms);
	friend String Right(const String, int noofterms);
	friend String Reverse(const String);
	friend String Rtrim(const String);
	friend String Ltrim(const String);
	friend String Alltrim(const String);
	friend String ToLower(const String);
	friend String ToUpper(const String);
	friend String Proper(const String);
	friend String Stuff(const String, char tofill);
	friend String Replace(const String mainstr, const String thisstr,const   String withstr);
	friend String Insert(const String mainstr,const String thisstr,  int at);
	friend String Remove(const String mainstr, const  String thisstr);
	friend String Lshift(const String, int noofpos) ;
	friend String Rshift(const String, int noofpos);
	friend boolean Palindrome(const String);
	friend boolean Find(const String mainstr, const String thisstr);
	friend boolean IsUpper(const String, int upto);
	friend boolean IsLower(const String, int upto);
	friend boolean IsAlpha(const String, int upto);
	friend boolean IsNum(const String, int upto);
	friend int Length(const String);
	friend int FindPos(const String mainstr, const  String ofstr);
	friend char Charat(const String, int pos);
	friend double DouValue(const String);
	friend int IntValue(const String);	

private :
	char *ptr;
	int length;	
	
public :
	String();
	String(int);
	String(char *);
	String(const String &);
	~String();
	boolean operator==(const String);
	boolean operator>=(const String);
	boolean operator<=(const String);
	boolean operator>(const String);
	boolean operator<(const String);
	boolean operator!=(const String);
	String operator+(const String);	
	void operator+=(const String);
	void operator=(const String);
	
};
//END OF THE CLASS
//
#endif
