
#include <iostream>

using namespace std;


/*
* Example 1: If a child class overrides, base class method which is overloaded in base class, i.e. fuction overloading, then either it should 
*			define all of them or if wants to override just one of them thn use the keyword using.
*/
//Example - 1
/*
class A
{
public:
	void fun() {  cout << "A::fun()" << endl; }
	void fun(int x) { cout << "A::fun(int)" << endl; }
};

class B : public A
{
public:
//	using A::fun;
	void fun() {  cout << "B::fun()" << endl; }
	void fun(int x) {  cout << "B::fun(int)" << endl; }
	void fun(char x) {  cout << "B::fun(char)" << endl; }
};
*/

/*
* Example 2: Is to try out if we can call pure virtual method from constructor or not, as object is not created yet, so no definite call can
* be defined by linker, so it will throw an error while compiling or runtime.
* This pure virtual method call error will come at runtime if we use any shared objet function, being called during construction of object, 
* here it will compile but throw error at runtime, detected this when I tried to start a thread from constructor itself, and the thread
* callback function was calling a pure virtual method.
* When we call a virtual function from constructor, the method defined in that class is called
*/

//Example - 2
class A
{
	public:
		A() { run(); }
		//void virtual run() =0;
		virtual void run() { cout << "A::run : " << this << endl; }
};

class B : public A 
{
	public:
		B() { run(); }
		void run() { cout << "B::run" << this <<  endl; }
};
int main(int argv, char** argc)
{
	B ob;
	A* ob1 = &ob;
	ob.run();
	ob1->run();
	return 0;
}
