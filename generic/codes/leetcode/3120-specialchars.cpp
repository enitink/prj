class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool small[26] = {};
        bool capital[26] = {};
        int i = 0;
        int lenw = word.length();
        for (;i<lenw;++i) {
            if (word[i] > 'Z')
                small[word[i]-'a'] = true;
            else
                capital[word[i]-'A'] = true;
        }
        int result = 0;
        for(i=0; i<26; ++i) {
            if (small[i] && capital[i])
                ++result;
        }
        return result;
    }
};