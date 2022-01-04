/******************************SOLVED*******************************************
516. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*******************************************************************************/

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