class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue <int> maxheap;
        int i = 0;
        int lh = happiness.size();
        for( ;i<lh; ++i) {
            maxheap.push(happiness[i]);
        }
        long long int result = 0;
        for (i=0; i<k; ++i) {
            int lsum = maxheap.top() - i;
            lsum = (lsum < 0) ? 0 : lsum;
            result += lsum;
            maxheap.pop();
        }
        return result;
    }
};