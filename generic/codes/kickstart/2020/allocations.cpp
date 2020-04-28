#include <iostream> 
#include <set>

using namespace std;

int main()
{
    int T, N, B, d, caseno = 1;
    cin >> T;
    multiset<int> myset;
    while (T--)
    {
        cin >> N >> B;
        myset.clear();
        while (N--)
        {
            cin >> d;
            myset.insert(d);
        }
        int res = 0, sum = 0;
        for(multiset<int>::iterator it = myset.begin();
                it != myset.end(); ++it)
        {
            sum += *it;
            if (sum <= B)
            {
                ++res;
            }
            else
                break;
        }
        cout << "Case #" << caseno << ": " << res << endl;
        ++caseno;
    }
}