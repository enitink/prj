/******************************SOLVED*******************************************
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

Solution : Sliding window, whenever we find repeating character, we move our
window one ahead of the last occurance and continue further to see if length has
increased.
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        int arr[128] = {};
        int i = 0, j = 0;
        for (; i < s.length(); ++i)
        {
            j = (arr[s[i]] > j) ? arr[s[i]] : j;
            result = (result > (i-j+1)) ? result : (i-j+1);
            arr[s[i]] = i + 1;
        }
        return result;
    }
};

int main()
{
    Solution ob;

    cout << ob.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << ob.lengthOfLongestSubstring("bbbbb") << endl;
    cout << ob.lengthOfLongestSubstring("pwwkew") << endl;
    cout << ob.lengthOfLongestSubstring("aabaaabpwwkew") << endl;
    cout << ob.lengthOfLongestSubstring("ckilbkdefgh") << endl;

    return 0;
}