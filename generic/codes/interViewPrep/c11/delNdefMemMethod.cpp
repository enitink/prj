//to tell compiler, which method is present, and which default method is not present
#include <iostream>

using namespace std;

class A
{
private:
	static A* insTance;
	static int num;
private:
	A()=default;
public:
	static A* getA();
	A(const A& ) = delete;
	A& operator=(const A&) = delete;
};

int A::num = 0;
A* A::insTance = 0;

A* A::getA()
{
	if(num)
		return A::insTance;
	++num;
	return new A;
}

int main()
{
	A* ob = A::getA();
	A obb(*ob);
	
	return 0;	
}
