#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        int scount = 1 << nums.size();

        for(int i = 0; i < scount; ++i)
        {
            vector<int> lresult;
            int tempi = i;
            int pos = 0;
            while(tempi)
            {
                if (tempi&1)
                {
                    lresult.push_back(nums[pos]);
                }
                tempi >>= 1;
                ++pos;
            }
            result.push_back(lresult);
        }
        return result;
    }
};

void displayVector(vector<vector<int> >& result)
{
    vector<vector<int> >::iterator itr = result.begin();
    vector<vector<int> >::iterator eitr = result.end();

    for( ; itr != eitr; ++itr)
    {
        vector<int>::iterator litr = itr->begin();
        vector<int>::iterator leitr = itr->end();

        cout << "[";
        for( ; litr != leitr; ++litr)
            cout << *litr << ", ";
        cout << "] ,";
    }
    return;
}

int main()
{
    Solution ob;

    {
        int maxarr[] = {1,2,3};
        int i = 0;
        vector<int> nums;
        for (; i < 3; ++i)
            nums.push_back(maxarr[i]);
        vector<vector<int> > result = ob.subsets(nums);

        displayVector(result);
    }
    return 0;
}