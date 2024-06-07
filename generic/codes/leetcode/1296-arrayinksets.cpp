class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int lnums = nums.size();
        if (lnums%k)
            return false;
        map<int,int> freq;
        for(auto& n : nums) {
            freq[n]++;
        }
        while(!freq.empty()) {
            int b = freq.begin()->first;
            for(int i=0; i<k; ++i) {
                if (freq[b+i] == 0)
                    return false;
                freq[b+i]--;
                if (freq[b+i] < 1) {
                    freq.erase(b+i);
                }
            }
        }
        return true;
    }
};