//: C08:ConstructorOrder.cpp
// Order of constructor calls
#include <iostream>
#include <typeinfo>
#include <memory>

using namespace std;

template<int id> class Announce {
public:
  Announce() {
    cout << typeid(*this).name()
         << " constructor " << endl;
  }
  ~Announce() {
    cout << typeid(*this).name()
         << " destructor " << endl;
  }
};

class X : public Announce<0> {
  Announce<1> m1;
  Announce<2> m2;
public:
  X() { cout << "X::X()" << endl; }
  ~X() { cout << "X::~X()" << endl; }
};

int main() {
 X x;
 auto_ptr <Announce<0>> ptr(new Announce<0>);

 cout << "New X : " << typeid(*ptr).name() << endl;
}
