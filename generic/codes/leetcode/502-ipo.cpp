typedef struct _pc{
    int pro;
    int cap;
}pc;


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int i = 0, len = profits.size(), result = w;
        
        auto compareC = [](const pc& a, const pc& b) { return a.cap > b.cap; };
        auto compareP = [](const pc& a, const pc& b) { return a.pro < b.pro; };
        
        priority_queue<pc, vector<pc>,decltype(compareP)> pq_profit(compareP); ;
        priority_queue<pc, vector<pc>, decltype(compareC)> pq_capital(compareC);

        for(i=0;i<len;++i){
            pq_capital.emplace(profits[i], capital[i]);
        }
        while(k--){
            while (!pq_capital.empty() && pq_capital.top().cap <= result){
                pq_profit.push(pq_capital.top()), pq_capital.pop();
            }
            if (pq_profit.empty())
                break;
            result += pq_profit.top().pro;
            pq_profit.pop();
        }

        return result;
    }
};