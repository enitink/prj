/*****************************************SOLVED***************************************************
821. Shortest Distance to a Character

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

 

Example 1:

Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
Example 2:

Input: s = "aaab", c = "b"
Output: [3,2,1,0]
 

Constraints:

1 <= s.length <= 104
s[i] and c are lowercase English letters.
It is guaranteed that c occurs at least once in s.
*************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int slen = s.length();
        int i = 0;
        vector<int> cpos;
        for ( ; i<slen; ++i)
        {
            if (c == s[i])
                cpos.push_back(i);
        }
        vector<int> res;
        res.resize(slen, 105);
        int cposlen = cpos.size();
        int j = 0;

        for(i=0; i<slen; ++i)
        {
            if (c != s[i])
            {
                for (j=0; j<cposlen; ++j)
                {
                    res[i] = (res[i] > (abs(cpos[j] - i))) ? (abs(cpos[j] - i)) : res[i];
                }
            }
            else
                res[i] = 0;
        }
        return res;
    }
};

void printVector(const vector<int>& vec)
{
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator eiter = vec.end();

    cout << "[";
    for ( ; iter != eiter; ++iter)
    {
        if (iter != vec.begin())
            cout << ",";
        cout << *iter;
    }
    cout << "]" << endl;

}

int main()
{
    Solution ob;

    {
        vector<int> vec = ob.shortestToChar("loveleetcode", 'e');
        printVector(vec);
    }
    {
        vector<int> vec = ob.shortestToChar("aaab", 'b');
        printVector(vec);
    }
    return 0;
}