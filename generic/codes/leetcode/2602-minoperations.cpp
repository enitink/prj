#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int qlen = queries.size(), i = 0;
        vector<long long> result(qlen);

        for( ;i<qlen; ++i)
        {
            result[i] =0;
            for(int j=0; j<nums.size(); ++j)
                result[i] += abs(nums[j] - queries[i]);
        }
        return result;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,2,3,4,5};
        vector<int> queries = {1,3};
        vector<long long> result = s.minOperations(nums, queries);
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
    cout << endl;
    return 0;
}