#ifndef _MY_FIRST_CGI_
#define _MY_FIRST_CGI_

#include <string>

using namespace std;

namespace cgi { namespace lib {

class MyFirstCgi
{
	private:
		string __resp;
	public:
		MyFirstCgi();
		~MyFirstCgi();
		
		bool	prepareRspString();
		string& getRespString() { return __resp; }
};

}} //cgi::lib namespace 
#endif //_MY_FIRST_CGI_
