#include <cstdlib>
#include "myFirstCgi.h"

using namespace std;

namespace cgi { namespace lib {

MyFirstCgi::MyFirstCgi() { }

MyFirstCgi::~MyFirstCgi() { }

bool MyFirstCgi::prepareRspString()
{
	string query = getenv("QUERY_STRING");
	__resp = "";
	__resp += "Content-Type: text/html\n\n";
	__resp += ("<html><head><title>Welcome message</title></head><body><h1>Greetings!</h1><p>Welcome</p>");
	if ( query == "" )
		__resp += "no query string";
	else
		__resp += ("<p>The query string is: " + query + "</p>");
	__resp += "</body></html>";
	return 0;
}

}} //cgi::lib namespace
