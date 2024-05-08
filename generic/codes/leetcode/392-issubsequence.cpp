class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        
        int i = 0;
        int j = 0;
        
        for( ;i<tlen && j<slen; ++i)
        {
            if (s[j] == t[i])
            {
                ++j;
            }
        }
        return (j == slen) ?  true : false;
    }
};