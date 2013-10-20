#include <iostream>
#include <memory>

using namespace std;

class base0
{
private:
	int i;
	int j;
public :
	base0(int i, int j) : i(i), j(j){cout << endl << "Base0 constructor";}
	base0() {cout << endl << "Base0 normal constructor";}
	base0(const base0& ob){cout << endl << "Base0 copy constructor";}
	base0 operator=(base0 ob){cout << endl << "Base0 ="; return ob;}
	int& refI(){return i;}
	int getI(){return i;}
	~base0(){cout << endl << "Base0 destructor";}
};

class base1
{
public :
	int i;
	base1(){cout << endl << "Base1 constructor";}
	~base1(){cout << endl << "Base1 destructor";}
	
	virtual void pureVirtual() = 0;
};

class base2
{
public :
	int i;
	base2(){cout << endl << "Base2 constructor";}
	~base2(){cout << endl << "Base2 destructor";}
};

class derived1 : public base2, public base1
{
public :
	derived1(){cout << endl << "Derived1 constructor";}
	~derived1(){cout << endl << "Derived1 destructor";}
	
	virtual void pureVirtual() {cout << endl << "Virtual";}
};

class derived2 : public base1, public base2
{
public :
	derived2(){cout << endl << "Derived2 constructor";}
	~derived2(){cout << endl << "Derived2 destructor";}

	virtual void pureVirtual() {cout << endl << "Virtual";}
};

class derived3 : private base1
{
public:
	base1::i;

public :
	derived3(){cout << endl << "Derived3 constructor";}
	~derived3(){cout << endl << "Derived3 destructor";}

	virtual void pureVirtual() {cout << endl << "Virtual";}
};

base0& tryFunc()
{
	cout << endl << "tryFunc called";
	base0 ob(10, 20);
	return ob;
}

int main()
{
	base0 ob(10, 20);
//	tryFunc();
//	base0 ob1;

//	cout << endl << "ob i j " << ob.i << " " << ob.j << "   ob1 i j " << ob1.i << " " << ob1.j << endl;

//	int *ptr = &(ob.refI());
	//cout << endl << ptr << " " << *ptr << " " << ++ptr << " " << *(ptr);
//	cout << endl << ob.getI();
//	*ptr = 100;
//	cout << endl << ob.getI();

	cout << "just checking";
	cout << "if these things work or not";
	return 0;
}
