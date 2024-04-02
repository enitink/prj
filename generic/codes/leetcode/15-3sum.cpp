#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
        vector<vector<int> > threeSum(vector<int>& nums) {
        int lenn = nums.size(), i = 0;
        //sort the input
        sort(nums.begin(), nums.end());

        vector<vector<int> > result;
        for(i=0 ; i<lenn; ++i)
        {
            int num = nums[i];
            if ((i > 0) && (num == nums[i-1]))
                continue;

            int start = i + 1, end = lenn - 1;
            while(start < end)
            {
                int threesum = num + nums[start] + nums[end];
                if (threesum > 0)
                {
                    end--;
                }
                else if (threesum < 0)
                {
                    start++;
                }
                else
                {
                    vector<int> lresult;
                    lresult.push_back(num); lresult.push_back(nums[start]); lresult.push_back(nums[end]);
                    result.push_back(lresult);
                    start++;
                    while((nums[start] == nums[start - 1]) && (start < end))
                        start++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        int tar[] = {-3,3,4,-3,1,2};
        vector<int> heights(tar, tar+6);
        vector<vector<int> > result = ob.threeSum(heights);
        vector<vector<int> >::iterator it = result.begin();
        vector<vector<int> >::iterator eit = result.end();

        cout << "[";
        for(; it != eit; ++it)
        {
            cout << "[" << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << "]" << ",";
        }
        cout << "]";
    }
    cout << endl;
    {
        int tar[] = {-1,0,1,2,-1,-4};
        vector<int> heights(tar, tar+6);
        vector<vector<int> > result = ob.threeSum(heights);
        vector<vector<int> >::iterator it = result.begin();
        vector<vector<int> >::iterator eit = result.end();

        cout << "[";
        for(; it != eit; ++it)
        {
            cout << "[" << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << "]" << ",";
        }
        cout << "]";
    }
    cout << endl;
    {
        int tar[] = {0,1,1};
        vector<int> heights(tar, tar+3);
        vector<vector<int> > result = ob.threeSum(heights);
        vector<vector<int> >::iterator it = result.begin();
        vector<vector<int> >::iterator eit = result.end();

        cout << "[";
        for(; it != eit; ++it)
        {
            cout << "[" << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << "]" << ",";
        }
        cout << "]";
    }
    cout << endl;

    {
        int tar[] = {0,0,0};
        vector<int> heights(tar, tar+3);
        vector<vector<int> > result = ob.threeSum(heights);
        vector<vector<int> >::iterator it = result.begin();
        vector<vector<int> >::iterator eit = result.end();

        cout << "[";
        for(; it != eit; ++it)
        {
            cout << "[" << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << "]" << ",";
        }
        cout << "]";
    }
    cout << endl;
    return 0;
}