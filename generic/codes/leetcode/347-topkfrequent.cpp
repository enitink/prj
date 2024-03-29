#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class FrequencyData {
public:
    FrequencyData(int d, int f): data(d), frequency(f) {}
    FrequencyData(): data(0), frequency(0) {}
    int data;
    int frequency;
};

class Compare {
public:
    bool operator()(FrequencyData below, FrequencyData above)
    {
        if (below.frequency < above.frequency) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mymap;
        int nlen = nums.size(), i = 0;
        for ( ; i<nlen; ++i)
        {
            if (mymap.find(nums[i]) != mymap.end())
            {
                mymap[nums[i]]++;
            }
            else
                mymap[nums[i]] = 1;
        }
        map<int, int>::const_iterator itr = mymap.begin();
        map<int, int>::const_iterator eitr = mymap.end();
        priority_queue<FrequencyData, vector<FrequencyData>, Compare> ds;

        for ( ; itr != eitr; ++itr)
        {
            FrequencyData ob(itr->first, itr->second);
            ds.push(ob);
        }

        vector<int> result;
        while((ds.empty() == false) && (k > 0))
        {
            FrequencyData d = ds.top();
            ds.pop();
            result.push_back(d.data);
            --k;
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        int arr[] = {1,1,1,2,2,3};
        vector<int> nums(arr, arr+6);
        int i = 0;
        vector<int> result = ob.topKFrequent(nums, 2);
        int rlen = result.size();
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }

    {
        vector<int> nums; nums.push_back(1);
        int i = 0;
        vector<int> result = ob.topKFrequent(nums, 1);
        int rlen = result.size();
        for(i=0; i<rlen; ++i)
            cout << result[i] << " ";
        cout << endl;
    }
}