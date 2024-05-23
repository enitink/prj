class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> posmap;
        int lenn = nums.size();
        int i = 0;
        for (;i<lenn;++i) {
            if (posmap.find(nums[i]) != posmap.end()) {
                if (i-posmap[nums[i]] <= k)
                    return true;
                posmap[nums[i]] = i;
            } else {
                posmap[nums[i]] = i;
            }
        }
        return false;
    }
};