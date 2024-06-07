class Solution {
    
public:
    int longestPalindrome(string s) {
        int sfreq[26] = {};
        int bfreq[26] = {};
        for(auto c : s) {
            if (c & 32)
                sfreq[c-'a']++;
            else
                bfreq[c-'A']++;
        }
        int odd = 0;
        for (int i=0;i<26;++i){
            if (sfreq[i]%2)
                ++odd;
            if (bfreq[i]%2)
                ++odd;
        }

        return (odd) ? s.length() - odd + 1 : s.length();
    }
};