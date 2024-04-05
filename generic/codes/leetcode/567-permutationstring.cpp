#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        char cmap[26] = {};
        int s1len = s1.length(), s2len = s2.length(), i;
        if (s2len < s1len)
            return false;
        for( i=0; i<s1len; ++i)
            cmap[s1[i] - 'a']++;
        char lmap[26] = {};
        int ls1 = s1len, st = 0;
        for( i=0; i<s2len; ++i)
            lmap[s2[i] - 'a']++;
        memcpy(lmap, cmap, 26);
        for ( i=0; i<s2len; ++i )
        {
            if(lmap[s2[i] - 'a'])
            {
                --lmap[s2[i] - 'a'];
                --ls1;
            }
            else
            {
                i = st;
                st = st+1;
                memcpy(lmap, cmap, 26);
                ls1 = s1len;
            }
            if (ls1 == 0)
                return true;
        }
        
        return false;
    }
};

int main()
{
    Solution ob;

    cout << ob.checkInclusion("ab", "eidbaooo") << endl;
    cout << ob.checkInclusion("ab", "eidboaoo") << endl;
    cout << ob.checkInclusion("ab", "abaooo") << endl;
    cout << ob.checkInclusion("adc", "dcda") << endl;
    cout << ob.checkInclusion("abcde", "dabcde") << endl;
    cout << ob.checkInclusion("abc","ccccbbbbaaaa") << endl;
    cout << ob.checkInclusion("adce", "dcedeac") << endl;

    return 0;
}