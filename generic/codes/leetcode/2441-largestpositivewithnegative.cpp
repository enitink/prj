class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int arr[1001];
        int i = 0;
        for (;i<1001;++i)
            arr[i] = 1001;

        int lnums = nums.size();
        int result = -1;
        for(i=0;i<lnums;++i){
            if (arr[abs(nums[i])] == 1001)
                arr[abs(nums[i])] = nums[i];

            if (arr[abs(nums[i])] == nums[i])
                continue;
            
            if (abs(nums[i]) > result)
                result = abs(nums[i]);
        }
        return result;
    }
};