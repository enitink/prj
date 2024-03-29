#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int nlen = nums.size(), i = 0, j = 0;
        vector<long long> result(nlen);
        map<int, vector<int> > valmap;

        for ( ;i<nlen; ++i)
        {
            if(valmap.find(nums[i]) != valmap.end())
                valmap[nums[i]].push_back(i);
            else
            {
                vector<int> d;
                d.push_back(i);
                valmap[nums[i]] = d;
            }
        }
        map<int, vector<int> >::const_iterator itr = valmap.begin();
        map<int, vector<int> >::const_iterator eitr = valmap.end();
        for( ; itr != eitr; ++itr)
        {
            vector<int> lv = itr->second;
            int lvlen = lv.size();
            long long total = 0;
            for(i=1; i<lvlen; ++i)
            {
                total += (lv[i] - lv[0]);
            }
            result[lv[0]] = total;
            for(i=1; i<lvlen; ++i)
            {
                long long dist = lv[i] - lv[i - 1];
                total += dist * i;
                total -= dist * (lvlen - i);
                result[lv[i]] = total;
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        int arr[] = {1,3,1,1,2};
        vector<int> nums(arr, arr+5);
        int i = 0;
        vector<long long> result = ob.distance(nums);
        int rlen = result.size();
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }

    {
        int arr[] = {1,3,1,1,2,5,1};
        vector<int> nums(arr, arr+7);
        int i = 0;
        vector<long long> result = ob.distance(nums);
        int rlen = result.size();
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }

    
    {
        vector<int> nums;
        int i = 0, d;
        for (; i< 100000; ++i)
        {
            cin >> d;
            nums.push_back(d);
        }
        vector<long long> result = ob.distance(nums);
        int rlen = result.size();
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}