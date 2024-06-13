class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lnums = nums.size();
        int zero=0, two = lnums-1, one= 0, temp;
        
        while (one <= two) {
            if (nums[one] == 0) {
                temp = nums[one];
                nums[one] = nums[zero];
                nums[zero] = temp;
                one++;
                zero++;
            } else if (nums[one] == 1) {
                one++;
            }
            else {
                temp = nums[one];
                nums[one] = nums[two];
                nums[two] = temp;
                two--;
            }
        }
    }
};