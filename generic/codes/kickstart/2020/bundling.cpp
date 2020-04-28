#include <iostream> 
#include <set>
#include <string>

using namespace std;

int main()
{
    int T, N, K, caseno = 1;
    string str;
    cin >> T;
    multiset<string> myset;

    while(T--)
    {
        cin >> N >> K;
        myset.clear();
        while (N--)
        {
            cin >> str;
            myset.insert(str);
        }
        for(multiset<string>::iterator it = myset.begin();
            it!= myset.end(); ++it)
        {
            cout << endl << *it;
        }
    }


    return 0;
}