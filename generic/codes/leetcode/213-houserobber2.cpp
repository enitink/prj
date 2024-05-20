class Solution {

private:
    int helper(vector<int>& nums, int st, int end) {
        int i = st, rob1 = 0, rob2 = 0;
        if (st >= end)
            return nums[0];
        for(;i<end;++i) {
            int temp = (rob1 + nums[i]) > nums[i] ? (rob1 + nums[i]) : nums[i];
            temp = (temp > rob2) ? temp : rob2;
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
public:
    int rob(vector<int>& nums) {
        int lnums = nums.size();
        int h1 = helper(nums, 0, lnums - 1);
        int h2 = helper(nums, 1, lnums);
        
        return h1 > h2 ? h1 : h2;
    }
};