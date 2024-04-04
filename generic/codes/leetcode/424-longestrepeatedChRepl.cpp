#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int slen = s.length();
        int i = 0, nxtst = 0, st = 0;
        for ( ;i<slen;)
        {
            int lresult = 0;
            int lk = k;
            char stchar = s[i];
            nxtst = -1;

            while (i<slen)
            { 
                if (s[i] != stchar)
                {
                    if (nxtst == -1)
                        nxtst = i;
                    if (lk)
                        --lk;
                    else
                        break;
                }
                ++lresult;
                ++i;
            }
            if ((i >= slen) && (lk))
            {
                while((st > 0) && lk)
                {
                    ++lresult;
                    --st; --lk;
                }
            }
            result = lresult > result ? lresult : result;
            if (nxtst == -1)
                break;
            i = st = nxtst;
        }

        return result;
    }
};

int main()
{
    Solution ob;

    cout << ob.characterReplacement("ABAB", 2) << endl ;
    cout << ob.characterReplacement("AABABBA", 1) << endl;
    cout << ob.characterReplacement("AAAAAAA", 1) << endl;
    cout << ob.characterReplacement("AAABAAA", 1) << endl;
    cout << ob.characterReplacement("AAABBBAB", 0) << endl;
    cout << ob.characterReplacement("A", 1) << endl;
    cout << ob.characterReplacement("ABCDEFGHIJKLMNO", 14) << endl;
    cout << ob.characterReplacement("ABBB", 2) << endl;

    return 0;
}