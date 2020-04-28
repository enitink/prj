#include <iostream>

using namespace std;

int main()
{
    int m_size = 8;
    for (int i = 0 ; i < 100; ++i)
        cout << endl << (i & (m_size - 1));
    return 0;
}