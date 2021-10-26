/************************************SOLVED********************************************************
1961. Check If String Is a Prefix of Array

Given a string s and an array of strings words, determine whether s is a prefix string of words.

A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.

Return true if s is a prefix string of words, or false otherwise.

 

Example 1:

Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
Output: true
Explanation:
s can be made by concatenating "i", "love", and "leetcode" together.
Example 2:

Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
Output: false
Explanation:
It is impossible to make s using a prefix of arr.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
1 <= s.length <= 1000
words[i] and s consist of only lowercase English letters.

*************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        int slen = s.length();
        vector<string>::iterator itr = words.begin();
        vector<string>::iterator eitr = words.end();

        int si = 0;

        for (; itr != eitr; ++itr)
        {
            int li = 0;
            int llen = (*itr).length();
            for (; (li < llen) && (si < slen); ++li, ++si)
            {
                if (s[si] != (*itr)[li])
                    return false;
            }
            if (li < llen)
                return false;
            if (si == slen)
                break;
        }
        return (si == slen) ? true : false;
    }
};

int main()
{
    Solution ob;

    {
        string s("a");
        vector<string> words;
        words.push_back("aa");
        words.push_back("aaa");
        words.push_back("banana");
        words.push_back("nahi");
        cout << ob.isPrefixString(s, words) << endl;
    }
    {
        string s("iloveleetcode");
        vector<string> words;
        words.push_back("i");
        words.push_back("love");
        words.push_back("leetcode");
        words.push_back("apples");
        cout << ob.isPrefixString(s, words) << endl;
    }
    {
        string s("iloveleetcode");
        vector<string> words;
        words.push_back("apples");
        words.push_back("i");
        words.push_back("love");
        words.push_back("leetcode");
        cout << ob.isPrefixString(s, words) << endl;
    }
    {
        string s("ccccccccc");
        vector<string> words;
        words.push_back("c");
        words.push_back("cc");
        cout << ob.isPrefixString(s, words) << endl;
    }
}