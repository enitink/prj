#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isOpenBracket(char c)
    {
        if (c == '(' || c == '{' || c == '[')
            return true;
        return false;
    }
    char matchingBracket(char c)
    {
        switch (c)
        {
            case ')':
                return '(';
            case '}':
                return '{';
            case ']':
                return '[';
        }
        return '[';
    }

    bool isValid(string s) {
        int len = s.length();
        int i = 0;
        std::stack<char> st;
        for ( ; i < len; ++i)
        {
            if (isOpenBracket(s[i]))
                st.push(s[i]);
            else
            {
                if ((st.size() <= 0) || (st.top() != matchingBracket(s[i])))
                    return false;
                st.pop();
            }
        }
        return (st.size()) ? false : true;
    }
};

int main()
{
    Solution ob;
    cout << ob.isValid("()") << endl;
    cout << ob.isValid("()[]{}") << endl;
    cout << ob.isValid("(]") << endl;
    return 0;
}