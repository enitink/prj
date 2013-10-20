#include <iostream>
#include <memory>

using namespace std;

class base
{
public :
	int i;
	base(int i) : i(i){cout << endl << "Base2 constructor " << i;}
	~base(){cout << endl << "Base2 destructor " <<  i;}
};

void changeOwnership(auto_ptr<base> p)
{
	cout << endl << "In changeOwnership";
	cout << endl << "p.i"  << p->i;
}

int main()
{
	base *p = new base(10);
	auto_ptr<base> p1(new base(20)), p2(p);
	cout << endl << "p1.i" << p1->i;

	//cout << endl << "p1.i" << p1->i;
	cout << endl << "p2.i" << p2->i;
//	base * p3 = p2.get();
//	cout << endl << "p3.i" << p3->i;
	
	changeOwnership(p2);
	return 0;
}
