#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    // int expandPalindrome(const string &s, int left, int right)
    // {
    //     int len = s.length();
    //     if (len <= 0 || left > right)
    //         return 0;

    //     while ((left >= 0) && (right < len) && (s[left] == s[right]))
    //     {
    //         --left;
    //         ++right;
    //     }

    //     return right - left - 1;
    // }

    ///@ brief : code reuses Longest Palindrome substring problem solution. But tries to find out
    ///          longest substring from begining only. And rest is reversed and attached in the
    ///          begining of the string.
    // string shortestPalindrome(string s)
    // {
    //     int len = s.length();
    //     if (0 == len)
    //         return "";
    //     int start = 0;
    //     int maxlen = 0;
    //     int i = 0;
    //     for (; i < len; ++i)
    //     {
    //         int len1 = expandPalindrome(s, i, i); //For odd number of
    //         int len2 = expandPalindrome(s, i, i + 1);
    //         int llen = (len1 > len2) ? len1 : len2;
    //         if (llen > maxlen && (0 == (i - ((llen - 1) / 2))))
    //         {
    //             start = i - ((llen - 1) / 2);
    //             maxlen = llen;
    //         }
    //     }

    //     if (start == 0)
    //     {
    //         string rev = s.substr(maxlen);
    //         reverse(rev.begin(), rev.end());
    //         s = rev + s;
    //     }

    //     return s;
    // }

    string shortestPalindrome(string s)
    {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        vector<int> f(n_new, 0);
        for (int i = 1; i < n_new; i++)
        {
            int t = f[i - 1];
            while (t > 0 && s_new[i] != s_new[t])
                t = f[t - 1];
            if (s_new[i] == s_new[t])
                ++t;
            f[i] = t;
        }
        return rev.substr(0, n - f[n_new - 1]) + s;
    }
};

int main()
{
    Solution ob;

    // cout << ob.shortestPalindrome("abcd") << endl;
    // cout << ob.shortestPalindrome("aacecaaa") << endl;
    // cout << ob.shortestPalindrome("a") << endl;
    // cout << ob.shortestPalindrome("aca") << endl;
    // cout << ob.shortestPalindrome("aabba") << endl;

    string s("aaecaaa");
    string result = ob.shortestPalindrome(s);
    cout << result << endl;

    return 0;
}
