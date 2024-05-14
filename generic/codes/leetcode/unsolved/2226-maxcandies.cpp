class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int lenp = candies.size(), i;
        int max = candies[0];
        for(i=0; i<lenp; ++i)
            max = (max > candies[i]) ? max : candies[i];
        if (lenp == k)
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
                int r = (candies[i] % mid) ? 1 : 0;
                time += ((candies[i] / mid) + r );
            }
            if (time <= k)
            {
                result = (result > mid) ? mid : result;
                end = mid - 1;
                mid = (st + end) / 2;
            } 
            else if (time > k)
            {
                st = mid + 1;
                mid = (st + end) / 2;
            }
        }

        return result;
    }
};