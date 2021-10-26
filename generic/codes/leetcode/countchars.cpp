/**************************************SOLVED*************************************************
1160. Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.

*************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int countChars[26] = {0};
        int lcountChars[26];
        int lchars = chars.length();
        int i = 0;
        for ( ;i<lchars;++i)
            countChars[chars[i]-'a']++;
        vector<string>::const_iterator iter = words.begin();
        vector<string>::const_iterator eiter = words.end();
        int result = 0;
        for ( ;iter!=eiter; ++iter)
        {
               memcpy(lcountChars, countChars, 26 * sizeof(int));
               int llchar = (*iter).length();
               for(i=0; i<llchar; ++i)
               {
                   lcountChars[(*iter)[i]-'a']--;
                   if (lcountChars[(*iter)[i]-'a'] < 0)
                   {
                       llchar = 0;
                       break;
                   }
               }
               result += llchar;
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        string s("atach");
        vector<string> words;
        words.push_back("cat");
        words.push_back("bt");
        words.push_back("hat");
        words.push_back("tree");
        cout << ob.countCharacters(words, s) << endl;
    }
    {
        string s("welldonehoneyr");
        vector<string> words;
        words.push_back("hello");
        words.push_back("world");
        words.push_back("leetcode");
        cout << ob.countCharacters(words, s) << endl;
    }
    return 0;
}