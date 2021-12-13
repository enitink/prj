/**************************************************************************************************
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
**************************************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    // Below solution doesn't works for all the cases.
    /* bool checkInclusion(string s1, string s2)
    {
        char s[26] = {0};
        int lens1 = s1.length();
        int i = 0;
        for (; i < lens1; ++i)
            ++s[s1[i] - 'a'];

        char sl[26] = {0};
        memcpy(sl, s, sizeof(s));
        int lens2 = s2.length();
        bool needsreset = false;
        for (i = 0; i < lens2; ++i)
        {
            if (sl[s2[i] - 'a'] > 0)
            {
                --sl[s2[i] - 'a'];
                int x = 0;
                {
                    x = sl[0] + sl[1] + sl[2] + sl[3] + sl[4] + sl[5] + sl[6] + sl[7] + sl[8] + sl[9] + sl[10] + sl[11] + sl[12] + sl[13] + sl[14] + sl[15] + sl[16] + sl[17] + sl[18] + sl[19] + sl[20] + sl[21] + sl[22] + sl[23] + sl[24] + sl[25];
                }
                if (x == 0)
                    return true;
                needsreset = true;
            }
            else if (needsreset)
            {
                if (s[s2[i]] - 'a')
                {
                    sl[s2[i] - 'a'] = s[s2[i] - 'a'] - 1;
                }
                else
                {
                    memcpy(sl, s, sizeof(s));
                    needsreset = false;
                }
            }
        }
        return false;
    } */
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


    return 0;
}