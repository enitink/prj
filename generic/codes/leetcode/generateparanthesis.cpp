/*****************************SOLVEDs******************************************
 * 22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

Constraints:

1 <= n <= 8
******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void helper(int n, int o, int c, string para, vector<string>& result){
        if( o==n && c == n)
        {
            result.push_back(para);
            return;
        }
        
        if(o < n)
        {
            helper(n, o+1, c, para + "(", result);
        }
        if(c<o)
        {
            helper(n, o, c+1, para + ")", result);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        helper(n, 0,0, "", result);
        
        return result;   
    }
};

void printVector(const vector<string>& vec)
{
    vector<string>::const_iterator iter = vec.begin();
    vector<string>::const_iterator eiter = vec.end();

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
        vector<string> result = ob.generateParenthesis(3);
        printVector(result);
    }
}