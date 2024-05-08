class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lnums = nums.size();
        int i = 1;
        int pos = 1;
        int lcount = 1;
        for (; i<lnums; ++i) {
            if (nums[i] == nums[i-1])
                ++lcount;
            else
                lcount = 1;
            if (lcount <= 2)
            {
                nums[pos] = nums[i];
                ++pos;
            }
        }
        return pos;
    }
};