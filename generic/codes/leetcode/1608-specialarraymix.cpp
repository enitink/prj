class Solution {
    
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        for (int i = 1; i <= N; i++) {
            vector<int>::iterator low = lower_bound(nums.begin(), nums.end(),  i);
            int k = low - nums.begin();
            
            if (N - k == i) {
                return i;
            }
        }
        
        return -1;
    }
};