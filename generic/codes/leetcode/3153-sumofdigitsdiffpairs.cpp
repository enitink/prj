class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int count[10][10];
        int lnums = nums.size();
        int i = 0, j = 0;
        for(;i<10;++i) {
            for(;j<10;++j) {
                count[i][j] = 0;
            }
        }
        for (i=0;i<lnums;++i) {
            int pos = 0;
            while(nums[i]) {
                count[pos][nums[i]%10]++;
                nums[i] /= 10;
                ++pos;
            }
        }
        long long result = 0;
        int k;
        for(i=0;i<10;++i){
            long long mul = 0;
            for(j=0;j<10;++j) {
                long long lsum = 0;
                for (k=j+1;k<10;++k) {
                    lsum += count[i][j] * count[i][k];
                }
                mul += lsum;
            }
            result += mul;
        }
        return result;
    }
};