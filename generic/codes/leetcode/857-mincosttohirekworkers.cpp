class Ratio {
public:
    Ratio(int n, int d) : num(n), den(d) {}
    int num;
    int den;
};

class Compare {
public:
    bool operator()(Ratio& a, Ratio& b)
    {
        return (long)(a.num * b.den) > (long)(b.num * a.den);
    }
};

class Compare1 {
public:
    bool operator()(Ratio& a, Ratio& b)
    {
        return a.den < b.den;
    }
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<Ratio, vector<Ratio>, Compare> pq;
        int len = quality.size(), i = 0;
        for(;i<len;++i) {
            pq.push(Ratio(wage[i], quality[i]));
        }
        priority_queue<Ratio, vector<Ratio>, Compare1> rpq;
        int sum = 0;
        double total = numeric_limits<double>::max();

        while(pq.empty() == false) {
            rpq.push(pq.top());
            sum += (pq.top().den);
            if (rpq.size() > k) {
                sum -= (rpq.top().den);
                rpq.pop();
            }
            if (rpq.size() == k) {
                double lsum = (sum * (double)pq.top().num)/(double)pq.top().den;
                if (total > lsum)
                    total = lsum;
            }
            pq.pop();
        
        }
        return total;
    }
};