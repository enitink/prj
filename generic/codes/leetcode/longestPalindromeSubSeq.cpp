#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int slen = s.length();
        int i, j, cl;
        int res[slen][slen];

        for (i=0; i<slen; ++i)
            res[i][i] = 1;
        
        for (cl=2; cl<=slen; ++cl)
        {
            for (i=0; i<slen-cl+1; ++i)
            {
                j = i + cl - 1;
                if(s[i] == s[j])
                    res[i][j] = (cl == 2) ? 2 : res[i+1][j-1]+2;
                else
                    res[i][j] = (res[i][j-1] > res[i+1][j]) ? res[i][j-1] : res[i+1][j];                
            }
        }
        return res[0][slen-1];
    }
};


int main()
{
    Solution ob;
    cout << ob.longestPalindromeSubseq("bbbab") << endl;
    cout << ob.longestPalindromeSubseq("cbbd") << endl;
    cout << ob.longestPalindromeSubseq("abcacba") << endl;
    cout << ob.longestPalindromeSubseq("aaa") << endl;
    return 0;
}