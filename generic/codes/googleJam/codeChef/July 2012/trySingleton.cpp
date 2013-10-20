#include <iostream>
#include <cstdio>

using namespace std;

class Singleton
{
private:
    static bool instanceFlag;
    static Singleton *single;
    Singleton()
    {
        //private constructor
    }
	~Singleton()
    {
        instanceFlag = false;
    }
public:
    static Singleton* getInstance();
    void method();
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
    if(! instanceFlag)
    {
        single = new Singleton();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void Singleton::method()
{
    cout << "Method of the singleton class" << endl;
}

int main()
{
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();

    Singleton sc3(*sc1);
    sc3.method();

///	printf("\n%d %d %d", sc1, sc2, &sc3);
     
    return 0;
}
