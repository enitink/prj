class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int lenq = queries.size();
        int lenn = nums.size();
        int i = 1;
        vector<int> v;
        for(;i<lenn;++i) {
            if ((nums[i]%2) == (nums[i-1]%2))
                v.push_back(i-1);
        }

        vector<bool> result;
        for(i=0;i<lenq;++i){
            std::vector<int>::iterator low,up;
            low=std::lower_bound (v.begin(), v.end(), queries[i][0]);
            if (low == v.end()) {
                result.push_back(true);
                continue;
            }
            else {
                up=std::lower_bound (v.begin(), v.end(), queries[i][1]);
                if (low == up)
                    result.push_back(true);
                else
                    result.push_back(false);
            }
        }
        return result;
    }
};