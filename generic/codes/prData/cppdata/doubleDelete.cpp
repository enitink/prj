#include <iostream>
#include <cstring>

using namespace std;

class B
{
public:
       B(){ cout<< "Cons B"<<endl; data = new char[128](); }
	   B(B& rhs) { cout << "CopyCons B" << endl; data = new char[128]; memcpy(data, rhs.data, 128 * sizeof(char)); }

       virtual ~B() {cout<<"Dtor B"<<endl; delete [] data; }

       char* data;
       virtual void fun() { cout<<"B fun"<<endl; }
};
 
class D : public B
{
public:
       D(){	cout<<"cons D"<<endl; myData = new char[128](); }
	   //D(D& rhs) { cout << "CopyCons D" << endl; myData = new char[128]; memcpy(myData, rhs.myData, 128 * sizeof(char)); }
       ~D() {cout<<"Dtor D"<<endl; delete [] myData; }
       char* myData;
       void fun() { cout<<"D fun"<<endl; }
};

int main (void)
{
       D d;
       B bd = d;
       D b(d);
	   return 0;
}
