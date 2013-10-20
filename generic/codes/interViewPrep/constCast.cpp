#include <iostream>
#include <typeinfo>
using namespace std;
 
int main(void)
{
    int a1 = 40;
    const volatile int* b1 = &a1;
    cout << "typeid of b1 " << typeid(b1).name() << '\n';
    int* c1 = const_cast <int *> (b1);
    cout << "typeid of c1 " << typeid(c1).name() << '\n';
    int a = 10;
    cout << "typeid of c1 " << typeid(a).name() << '\n';
    const char *ch;
    cout << "typeid of c1 " << typeid(ch).name() << '\n';
    cout << "typeid of c1 " << typeid(const_cast <char *> (ch)).name() << "\n";
    return 0;
}
