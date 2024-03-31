#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int i = 1;
        set<string> s;
        s.insert("()");
        for( ; i<n; ++i)
        {
            set<string> ls;
            set<string>::iterator it = s.begin();
            set<string>::iterator eit = s.end();
            for( ; it != eit; ++it)
            {
                string ps = *it;
                string tps;
                tps = "(" + ps + ")";
                ls.insert(tps); 
                tps = "()" + ps;
                ls.insert(tps);
                tps = ps + "()";
                ls.insert(tps);            
            }
            s = ls;
        }
        set<string>::iterator it = s.begin();
        set<string>::iterator eit = s.end();
        vector<string> result;
        for( ; it != eit; ++it)
        {
            result.push_back(*it);
        }
        return result;
    }
};

class Solution1 {
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
        if(c < o)
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

int main()
{
    Solution ob;
    Solution ob1;
    map<string, bool> mymap;

    {
        vector<string> result = ob.generateParenthesis(8);
        int rlen = result.size(), i = 0;
        sort(result.begin(), result.end());
        for( ; i<rlen; ++i)
        {
            mymap[result[i]] = true;
            //cout << result[i] << " ";
        }
        cout << result.size() << endl;
    }
    {
        vector<string> result = ob1.generateParenthesis(8);
        int rlen = result.size(), i = 0;
        for( ; i<rlen; ++i)
        {
            if (mymap.find(result[i]) == mymap.end())
                cout << result[i] << " ";
        }
        cout << result.size() << endl;
    }
}