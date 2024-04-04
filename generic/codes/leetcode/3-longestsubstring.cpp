/******************************SOLVED*******************************************
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