class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mmap;
        map<char, char> tmap;

        //map<char, vector<int>> 
        int slen = s.length();
        int tlen = t.length();
        if (slen != tlen)
            return false;
        int i = 0;
        for( ;i<slen; ++i) {
            if (mmap.find(s[i]) == mmap.end()) {
                mmap[s[i]] = t[i];
            }
            else {
                if (mmap[s[i]] != t[i])
                    return false;
            }
            if (tmap.find(t[i]) == tmap.end()) {
                tmap[t[i]] = s[i];
            }
            else {
                if (tmap[t[i]] != s[i])
                    return false;
            }
                
        }
        return true;
    }
};