#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int expandPalindrome(const string &s, int left, int right)
    {
        int len = s.length();
        if (len <= 0 || left > right) return 0;

        while( (left >=0) && (right < len) && (s[left] == s[right]) )
        {
            --left;
            ++right;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int len = s.length();
        if (0 == len)
            return "";
        int start = 0;
        int maxlen = 0;

        for(int i=0;i<len;++i)
        {
            int len1 = expandPalindrome(s, i, i);
            int len2 = expandPalindrome(s, i, i+1);
            int llen = (len1 > len2) ? len1 : len2;
            if (llen > maxlen)
            {
                    start = i - ((llen-1)/2);
                    maxlen = llen;
            }
        }

        return s.substr(start, maxlen);
    }
};

int main()
{
    Solution sol;
    {
        string s = "babad";
        cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    }
    {
        string s = "cbbd";
        cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    }
    {
        string s = "a";
        cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    }
    {
        string s = "ac";
        cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    }
    return 0;

}
