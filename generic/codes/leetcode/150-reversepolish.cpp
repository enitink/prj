#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
    int helper(int an, int bn, string op)
    {
        int i = 0;
        switch (op[0])
        {
        case '+':
            return an + bn;
        case '-':
            return an - bn;
        case '*':
            return an * bn;
        case '/':
            return an / bn;
        }
        return 0;
    }

    bool isOperator(string op)
    {
        if ((op == "+") || 
            (op == "-") || 
            (op == "*") || 
            (op == "/"))
                return true;
        return false;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        int tlen = tokens.size(), i = 0;
        for( ; i<tlen; ++i)
        {
            if(isOperator(tokens[i]))
            {
                int b = mystack.top(); mystack.pop();
                int a = mystack.top(); mystack.pop();

                int r = helper(a, b, tokens[i]);
                mystack.push(r);
            }
            else
            {
                int an = 0, lena = tokens[i].length(), mul = 1;
                for(int j = 0 ;j<lena; ++j)
                {
                    if (tokens[i][j] == '-')
                        mul = -1;
                    else
                        an = (an*10) + (tokens[i][j] - '0');
                }
                mystack.push(an * mul);
            }
        }
        return mystack.top();
    }
};

int main()
{
    Solution ob;
    {
        string inputs[] = {"2","1","+","3","*"};
        vector<string> tokens(inputs, inputs + 5);
        cout << ob.evalRPN(tokens) << endl;
    }
    {
        string inputs[] = {"4","13","5","/","+"};
        vector<string> tokens(inputs, inputs + 5);
        cout << ob.evalRPN(tokens) << endl;
    }
    {
        string inputs[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
        vector<string> tokens(inputs, inputs + 13);
        cout << ob.evalRPN(tokens) << endl;
    }
    return 0;
}