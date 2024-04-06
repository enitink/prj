#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class PositionSpeedData {
public:
    PositionSpeedData(int p, int s): position(p), speed(s) {}
    PositionSpeedData(): position(0), speed(0) {}
    int position;
    int speed;
};

class Compare {
public:
    bool operator()(PositionSpeedData below, PositionSpeedData above)
    {
        if (below.position < above.position) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    // 1. Sort the cars based on their position in descending order.
    // 2. Calculate the time taken by each car to reach the target.
    // 3. If the time taken by the car behind the current car is less than the current car, 
    // then the car behind will not be able to catch up with the current car, so it becomes a different fleet.
    // 4. If the time taken by the car behind the current car is more than the current car,
    // then the car behind will be able to catch up with the current car, this one becoes fleet wit the car in front.
           
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int splen = speed.size(), i = 0;
        vector<PositionSpeedData> spdata;
        for( ; i<splen; ++i)
        {
            PositionSpeedData psdata(position[i], speed[i]);
            spdata.push_back(psdata);
        }
        Compare ob;
        sort(spdata.begin(), spdata.end(), ob);

        stack<PositionSpeedData> st;
        st.push(spdata[splen - 1]);
        for(i=splen - 2; i>=0; --i)
        {
            long t1 = ceil((1.0 * (target - spdata[i].position) / spdata[i].speed) * 1000000);
            long t2 = ceil((1.0 * (target - st.top().position) / st.top().speed) * 1000000);
            if (t2 < t1)
                st.push(spdata[i]);
        }
        return st.size();
    }
};

int main()
{
    Solution ob;

    {
        vector<int> target={10,8,0,5,3};
        vector<int> speed={2,4,1,1,3};   
        cout << ob.carFleet(12, target, speed) << endl;
    }
    {
        int tar[] = {3};
        vector<int> target(tar, tar+1);
        int sp[] = {3};
        vector<int> speed(sp, sp+1);
        
        cout << ob.carFleet(10, target, speed) << endl;
    }
    {
        int tar[] = {0,2,4};
        vector<int> target(tar, tar+3);
        int sp[] = {4,2,1};
        vector<int> speed(sp, sp+3);
        
        cout << ob.carFleet(100, target, speed) << endl;
    }
    {
        int tar[] = {6,8};
        vector<int> target(tar, tar+2);
        int sp[] = {3,2};
        vector<int> speed(sp, sp+2);
        
        cout << ob.carFleet(10, target, speed) << endl;
    }
    {
        int tar[] = {8,3,7,4,6,5};
        vector<int> target(tar, tar+6);
        int sp[] = {10000000,4,4,4,4,4};
        vector<int> speed(sp, sp+6);
        
        cout << ob.carFleet(10, target, speed) << endl;
    }

    return 0;
}