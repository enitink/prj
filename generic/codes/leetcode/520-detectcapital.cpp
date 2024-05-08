class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allcapital = true;
        bool allsmalls = true;
        bool onlyfirstcapital = word[0] < 'a';

        int i =0;
        int lw = word.length();
        for(;i<lw; ++i)
        {
            if (word[i] >= 'a')
                allcapital = false;
            else if (word[i] < 'a') {
                allsmalls = false;
                if (i==0) continue;
                onlyfirstcapital = false;
            }
        }
        return (allcapital || allsmalls || onlyfirstcapital);     
    }
};