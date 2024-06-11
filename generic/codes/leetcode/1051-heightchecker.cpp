class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int result=0, i=0, lenh = heights.size();
        vector<int> heightscopy = heights;
        sort(heights.begin(), heights.end());
        for(;i<lenh;++i) {
            if (heightscopy[i] != heights[i])
                ++result;
        }
        return result;
    }
};