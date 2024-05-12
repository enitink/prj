#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
bool balanced(string& s)
{
    int ch[26] = {};
    int slen = s.length();
    for(int i = 0; i<slen;++i) {
        ch[s[i]-'a']++;
    }
    int l = 0;
    for(int j =0;j<26;++j)
        if (ch[j] == 0)
            continue;
        else {
            if (l==0)
                l = ch[j];
            else
                if (l != ch[j])
                    return false;
        }
    return true;
}
int helper(string s, int pos, vector<string> sv)
{
    int slen = s.length();
    if (slen-1 == pos)
    {
        int svlen = sv.size();
        int i = 0;
        int r = 0;
        for (;i<svlen;++i)
        {
            if (balanced(sv[i]))
                ++r;
        }
        return r;
    }
    vector<string> svl(sv.begin(), sv.end());
    svl.push_back(s.substr(pos,1));
    int r = helper(s,pos+1,svl);
    vector<string> svt(sv.begin(), sv.end());
    svt[svt.size()-1]+= s.substr(pos,1);
    int t = helper(s,pos+1,svt);
    
    return r < t ? r : t;
}
public:
    int minimumSubstringsInPartition(string s) {
        vector<string> sv;
        return helper(s,0,sv);
    }
};

int main()
{
    Solution s;
    cout << s.minimumSubstringsInPartition("fabccddg") << endl;

    return 0;
}