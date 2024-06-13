class Solution {
public:
    int countGoodSubstrings(string s) {
        int i = 0, slen = s.length(), result = 0, st = 0;
        int ch[26] = {0};
        for(;i<slen;++i){
            int index = s[i] - 'a';
            ch[index]++;
            while (ch[index] > 1) {
                ch[s[st]-'a']--;
                ++st;
            }
            if (i-st+1 == 3) {
                ++result;
                ch[s[st]-'a']--;
                ++st;
            }
        }
        return result;
    }
};