#include <iostream>
#include <cstdlib>
#include <unistd.h>


using namespace std;

class gThreadTest 
{
	public:
		virtual void* run()
		{
			while (true)
			{
       			sleep(6);
				cout << endl << "sleeping...";
			}
			return NULL;
		}
};
