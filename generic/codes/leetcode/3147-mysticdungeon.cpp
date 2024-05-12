class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int len = energy.size(), i = len-1;
        int result = -1001;
        for(;i>=0;--i) {
            if (i+k>=len){
                result = result < energy[i] ? energy[i] : result;
                continue;
            }
            energy[i] = energy[i] + energy[i+k];
            if (energy[i] > result)
                result = energy[i];
        }
        return result;
    }
};