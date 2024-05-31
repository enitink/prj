/*
How this works,
1- xor of all the elements will give xor of only the unique numbers, rest all will become 0. Let's call the uniques as a & b
2- finding the xored & = -xored, gives only the right most bit or the smallest bit that is set. now as this is set, means it's unique in one of a or b, it can't be in both of a & b;
3- So we segregate and xor all the elements based on that bit set or not set, all other elements which has that bit set will become 0 living only one of a or b
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int i = 0, lnums = nums.size();
        int xored = nums[i];
        for(i=1;i<lnums;++i){
            xored = xored ^ nums[i];
        }
        int least = 1;
        while((xored & least) == 0) {
            least = least << 1;
        }
        xored = least;
        vector<int> result = {0,0};
        for (i=0;i<lnums;++i){
            if ((nums[i] & xored) == 0)
            {
                result[0] ^= nums[i];
            }
            else
            {
                result[1] ^= nums[i];
            }
        }
        return result;
    }
};