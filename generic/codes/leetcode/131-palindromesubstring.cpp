#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }

    void helper(string s, int st, int end, vector<string> &path, vector<vector<string>> &result)
    {
        if (st > end)
        {
            result.push_back(path);
            return;
        }

        for(int i = st; i<=end; ++i)
        {
            if (isPalindrome(s, st, i))
            {
                path.push_back(s.substr(st, i-st+1));
                helper(s, i+1, end, path, result);
                path.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        helper(s, 0, s.size()-1, path, result);
        return result;
    }
};

void printvector(vector<vector<string>> &result)
{
    cout << "[";
    for (auto& r : result)
    {
        cout << "[";
        for (auto& c : r)
        {
            cout << c << " ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution sln;
    {
        string s = "aab";
        vector<vector<string>> result = sln.partition(s);
        printvector(result);
    }
    {
        string s = "a";
        vector<vector<string>> result = sln.partition(s);
        printvector(result);
    }
    {
        string s = "ab";
        vector<vector<string>> result = sln.partition(s);
        printvector(result);
    }
    {
        string s = "aabb";
        vector<vector<string>> result = sln.partition(s);
        printvector(result);
    }
    {
        string s = "aabbcc";
        vector<vector<string>> result = sln.partition(s);
        printvector(result);
    }
    return 0;
}