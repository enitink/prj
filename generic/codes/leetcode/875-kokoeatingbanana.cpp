#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lenp = piles.size(), i;
        int max = piles[0];
        for(i=0; i<lenp; ++i)
            max = (max > piles[i]) ? max : piles[i];
        if (lenp == h)
        {
            return max;
        }

        int st = 1, end = max, mid  = (st + end) / 2;
        int result = max;

        while(st <= end)
        {
            int time = 0;
            for(i=0; i<lenp; ++i)
            {
                int r = (piles[i] % mid) ? 1 : 0;
                time += ((piles[i] / mid) + r );
            }
            if (time <= h)
            {
                result = (result > mid) ? mid : result;
                end = mid - 1;
                mid = (st + end) / 2;
            } 
            else if (time > h)
            {
                st = mid + 1;
                mid = (st + end) / 2;
            }
        }

        return result;
    }
};

int main()
{
    Solution ob;

    {
        int maxarr[] = {3,6,7,11};
        int i = 0;
        vector<int> nums;
        for (; i < 4; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.minEatingSpeed(nums, 8) << endl;
    }
    {
        int maxarr[] = {30,11,23,4,20};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.minEatingSpeed(nums, 5) << endl;
    }
    {
        int maxarr[] = {30,11,23,4,20};
        int i = 0;
        vector<int> nums;
        for (; i < 5; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.minEatingSpeed(nums, 6) << endl;
    }
    {
        int maxarr[] = {873375536,395271806,617254718,970525912,634754347,824202576,694181619,20191396,886462834,442389139,572655464,438946009,791566709,776244944,694340852,419438893,784015530,588954527,282060288,269101141,499386849,846936808,92389214,385055341,56742915,803341674,837907634,728867715,20958651,167651719,345626668,701905050,932332403,572486583,603363649,967330688,484233747,859566856,446838995,375409782,220949961,72860128,998899684,615754807,383344277,36322529,154308670,335291837,927055440,28020467,558059248,999492426,991026255,30205761,884639109,61689648,742973721,395173120,38459914,705636911,30019578,968014413,126489328,738983100,793184186,871576545,768870427,955396670,328003949,786890382,450361695,994581348,158169007,309034664,388541713,142633427,390169457,161995664,906356894,379954831,448138536};
        int i = 0;
        vector<int> nums;
        for (; i < 81; ++i)
            nums.push_back(maxarr[i]);
        cout << ob.minEatingSpeed(nums, 943223529) << endl;
    }

    return 0;
}