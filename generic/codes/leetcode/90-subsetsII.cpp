class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        int loop = pow(2, len);
        int i, j;
        sort(nums.begin(), nums.end());
        set<vector<int>> setresult;
        for(i=0; i<loop; ++i){
            vector<int> lresult;
            for(j=0;j<len;++j) {
                int filter = 1 << j;
                if (i&filter)
                    lresult.push_back(nums[j]);
            }
            setresult.insert(lresult);
        }
        vector<vector<int>> result;
        for(auto& v : setresult)
            result.push_back(v);
        return result;
    }
};