/*******************************************************************************
Longest Common Substring

Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
Example 2:

Input: S1 = "ABC", S2 "ACB"
Output: 1
Explanation: The longest common substrings
are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the
function longestCommonSubstr() which takes the string S1, string S2 and their
length n and m as inputs and returns the length of the longest common substring
in S1 and S2.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).


Constraints:
1<=n, m<=1000
*******************************************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
    int helper(string &text1, string &text2,
               int s1st, int s1end,
               int s2st, int s2end)
    {
        if ((s1st > s1end) || (s2st > s2end))
            return 0;
        
        int result = 0;

        if (-1 != memoize[s1st][s2st])
            return memoize[s1st][s2st];

        int count = 0;
        int ls1st = s1st;
        int ls2st = s2st;
        while (text1[ls1st] == text2[ls2st])
        {
            ++count;
            ++ls1st;
            ++ls2st;
            if ((ls1st > s1end) || (ls2st > s2end))
                break;
        }
        result = count;

        {
            int lresult =
                helper(text1, text2, s1st + 1, s1end, s2st, s2end);
            int rresult =
                helper(text1, text2, s1st, s1end, s2st + 1, s2end);
            int locresult = (lresult > rresult) ? lresult : rresult;
            result = (result > locresult) ? result : locresult;
        }


        memoize[s1st][s2st] = result;
        return result;
    }

    int memoize[1001][1001];

    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int t1len = S1.size();
        int t2len = S2.size();
        int i, j;
        for (i = 0; i < t1len; ++i)
            for (j = 0; j < t2len; ++j)
                memoize[i][j] = -1;
        int result = helper(S1, S2,
                            0, t1len - 1,
                            0, t2len - 1);
        return result;
    }
};

int main()
{

    Solution ob;

    cout << ob.longestCommonSubstr("ABCDGH", "ACDGHR", 6, 6) << endl;
    cout << ob.longestCommonSubstr("ABC", "ACB", 3, 3) << endl;
    cout << ob.longestCommonSubstr("adac", "adadac", 4, 6) << endl;

    return 0;
}