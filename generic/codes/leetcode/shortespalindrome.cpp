#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s)
    {
        int len = s.length();
        int middle = len/2;
        for(int i = 0; i < middle; ++i)
        {
            if (s[i] != s[len - i - 1])
                return false;
        }
        return true;
    }
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

    string shortestPalindrome(string s) {
        int len = s.length();
        if (0 == len)
            return "";
        int start = 0;
        int maxlen = 0;
        int i = 0;
        for( ;i<len;++i)
        {
            int len1 = expandPalindrome(s, i, i); //For odd number of 
            int len2 = expandPalindrome(s, i, i+1);
            int llen = (len1 > len2) ? len1 : len2;
            if (llen > maxlen)
            {
                    start = i - ((llen-1)/2);
                    maxlen = llen;
            }
        }

        if (start == 0 && maxlen != len && maxlen > 1)
        {
            string rev = s.substr(maxlen);
            reverse(rev.begin(), rev.end());
            rev += s;
            return rev;
        }
        if (start == 0 && maxlen == len)
            return s;
        
        string result = s;
        for (i = 1; i < len; ++i)
        {
            result = s[i] + result;
            if (isPalindrome(result))
                break;
        }
        string result2 = s;
        string lresult2;
        for (i = len -1; i >= 1; --i)
        {
            lresult2 += s[i];
            if (isPalindrome(lresult2 + s))
            {
                result2 = lresult2 + s;
            } 
        }
        cout << result << " : " << result2 << endl;
        result = (result.length() < result2.length()) ? result : result2;
        
        return result;
    }
};

int main()
{
    Solution ob;

    // cout << ob.shortestPalindrome("abcd") << endl;
    // cout << ob.shortestPalindrome("aacecaaa") << endl;
    // cout << ob.shortestPalindrome("a") << endl;
    // cout << ob.shortestPalindrome("aca") << endl;
    cout << ob.shortestPalindrome("aabba") << endl;

    
    cout << endl;

    return 0;
}
