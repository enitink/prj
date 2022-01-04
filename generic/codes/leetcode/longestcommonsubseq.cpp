/*******************************SOLVED******************************************
1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common
subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative order
of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both
strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*******************************************************************************/

#include <iostream>

using namespace std;

//// Bottom down approach - Top down pending
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1len = text1.size();
        int t2len = text2.size();
        int i, j;
        for(i=0; i<t1len; ++i)
            for(j=0; j<t2len; ++j)
                memoize[i][j] = -1;
        
        int result =  helper(text1, text2,
                         0, text1.size() - 1,
                         0, text2.size() - 1 );

        return result;
    }
private:
    int helper(string& text1, string& text2,
                int t1st, int t1end,
                int t2st, int t2end)
    {
        if ( (t1st > t1end) || (t2st > t2end) )
            return 0;
        int result = 0;

        if (-1 != memoize[t1st][t2st])
            return memoize[t1st][t2st];

        if (text1[t1st] == text2[t2st])
        {
            result =
                1 + helper(text1, text2, t1st + 1, t1end, t2st + 1, t2end);
        }
        else
        {
            int lresult =
                     helper(text1, text2, t1st + 1, t1end, t2st, t2end);
            int rresult =
                     helper(text1, text2, t1st, t1end, t2st + 1, t2end);
            result = (lresult > rresult) ? lresult : rresult;
        }
        memoize[t1st][t2st] = result;
        return result;
    }

    int memoize[1001][1001];
};

int main()
{
    Solution ob;
    cout << ob.longestCommonSubsequence("abcde", "ace") << endl;
    cout << ob.longestCommonSubsequence("abc", "abc") << endl;
    cout << ob.longestCommonSubsequence("abc", "def") << endl;
    return 0;
}