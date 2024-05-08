class Solution {
public:
    int numberOfSpecialChars(string word) {
        int small[26] = {};
        int capital[26] = {};
        int i = 0;
        int lenw = word.length();
        int result = 0;
        for (;i<lenw;++i) {
            if (word[i] > 'Z')
                small[word[i]-'a'] = i+1;
            else
            {
                if (capital[word[i]-'A'] == 0)
                    capital[word[i]-'A'] = i+1;
            }
        }
        for(i=0; i<26; ++i)
        {
            if ((small[i]) && (small[i] < capital[i]))
                    ++result;
        }
        return result;
    }
};