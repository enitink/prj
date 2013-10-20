#include <iostream>

using namespace std;

int tryNestedClass(){

	int i = 0;
	static int si = 0;
	int* pi = &i;
	class NestedLocal{
	public:
		void Printing()
		{
			cout << "nested one" << endl;
			cout << si;
		}
	};

	NestedLocal ob;
	ob.Printing();
}

int main(){
	return 0;
}
