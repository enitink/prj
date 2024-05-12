class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ch[26] = {};
        int len=s.length();
        int i=0;
        for(;i<len;++i)
            ch[s[i]-'a'] = i;
        int sum = 0;
        for(i=0;i<len;++i)
            sum += abs(ch[t[i]-'a'] - i);
        return sum;
    }
};