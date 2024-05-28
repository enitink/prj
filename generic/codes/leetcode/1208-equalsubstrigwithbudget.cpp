class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int lens = s.length();
        int st = 0, i = 0;
        int result = 0;
        int lmax = 0;
        for(;i<lens;++i){
            lmax += (abs(s[i] - t[i]));
            if ((i - st + 1 > result) && (lmax <= maxCost))
                result = i - st + 1;
            while((lmax > maxCost) && (st <= i)) {
                lmax -= (abs(s[st] - t[st]));
                ++st;
            }
        }
        return result;
    }
};
