#include	<iostream>

using std::cout;
using std::cin;
using std::endl;

#include 	<cstdlib>

int main(	int argc, /*Number of strings in array argv*/
		char ** argv, /*Array of command line arguments*/
		char ** ppenv /*Array of environmental variables*/
	){

	int count;
	
	cout << endl << "command line arguments ";
	for(count = 0; count < argc; ++count)
		cout << endl << argv[count];

	
	cout << endl << "environment variables :";
	while( *ppenv != NULL)
		cout << endl << *(ppenv++);
	
	const char * p = getenv("GNOME_DESKTOP_SESSION_ID");
	cout << endl << "getenv : " << p << endl; 

	return 0;
}
