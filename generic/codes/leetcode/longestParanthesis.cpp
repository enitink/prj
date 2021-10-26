/******************************************SOLVED**************************************************
Given a string containing just the characters '(' and ')', find the length of the longest valid 
(well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.
**************************************************************************************************/

#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    
    int longestValidParentheses(std::string s)
    {
        std::cout << s << " : ";

        int len = s.length();
        int i = 0;

        // stack 'st' to keep location of the opening brackets
        std::stack<int> st;

        for ( ; i<len; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                if (st.empty())
                {
                    continue;
                }
                int pos = st.top();
                st.pop();
                s[pos] = 2;
                s[i] = 0;
            }
        }

        int lres = 0;
        int res = 0;

        for (i=0 ; i<len; ++i)
        {
            if (s[i] == 0 || s[i] == 2)
                lres += s[i];
            else
            {
                res = (lres > res) ? lres : res;
                lres = 0;
            }
        }
        return (lres > res) ? lres : res;
    }
};

int main()
{
    Solution ob;
    std::cout << ob.longestValidParentheses("(())") << std::endl;
    std::cout << ob.longestValidParentheses(")()())") << std::endl;
    std::cout << ob.longestValidParentheses("") << std::endl;
    std::cout << ob.longestValidParentheses("((((((()))))))") << std::endl;
    std::cout << ob.longestValidParentheses("()()()()()()()()") << std::endl;
    std::cout << ob.longestValidParentheses("(()))()()()") << std::endl;
    std::cout << ob.longestValidParentheses("(()()(()") << std::endl;


    return 0;
}