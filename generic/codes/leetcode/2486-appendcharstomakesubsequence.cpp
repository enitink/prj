class Solution {
public:
    int appendCharacters(string s, string t) {
        int sst = 0, tst = 0, lens = s.size(), lent = t.size();
        for(; sst < lens && tst < lent; ++sst) {
            if (s[sst] == t[tst])
                ++tst;
        }
        return lent - tst;
    }
};