class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int lnums = nums.size();
        int i = 1;
        for(;i<lnums;++i) {
            if ((nums[i]%2) == (nums[i-1]%2))
                return false;
        }
        return true;
    }
};