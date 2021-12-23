/*****************************SOLVED********************************************
 1163. Last Substring in Lexicographical Order

Given a string s, return the last substring of s in lexicographical order.

Example 1:

Input: s = "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
Example 2:

Input: s = "leetcode"
Output: "tcode"
 
Constraints:

1 <= s.length <= 4 * 105
s contains only lowercase English letters.
*******************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int slen = s.length();
        int startpos = 0;
        int i = 1;
        for ( ; i<slen; ++i)
        {
            if (s[i] > s[startpos])
            {
                startpos = i;
            }
            else if (s[i] == s[startpos])
            {
                int j = 0;
                while(((startpos + j) < i) && 
                    (s[startpos + j] == s[i + j]))
                {
                    ++j;
                }
                if (((startpos + j) < i) && (s[startpos + j] < s[i + j]))
                    startpos = i;
                else
                    i = i + j - 1;
            }
        }
        return s.substr(startpos, slen - startpos);
    }
};


int main()
{
    Solution ob;
    cout << ob.lastSubstring("cacacb") << endl;
    cout << ob.lastSubstring("cacabcb") << endl;
    cout << ob.lastSubstring("cacabc") << endl;
    cout << ob.lastSubstring("leetcode") << endl;
    cout << ob.lastSubstring("bbbbbb") << endl;
}

