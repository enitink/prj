class Solution {
public:
    int rob(vector<int>& nums) {
        int lnums = nums.size();
        int i = 0, rob1 = 0, rob2 = 0;
        for(;i<lnums;++i) {
            int temp = (rob1 + nums[i]) > nums[i] ? (rob1 + nums[i]) : nums[i];
            temp = (temp > rob2) ? temp : rob2;
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
};