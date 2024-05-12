class Fraction {
public:
    Fraction(int n, int d) : num(n), den(d) {}
    int num;
    int den;
};

class Compare {
public:
    bool operator()(Fraction& a, Fraction& b)
    {
        return (long)(a.num * b.den) > (long)(b.num * a.den);
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int i,j;
        int larr = arr.size();
        priority_queue<Fraction, vector<Fraction>, Compare> pq;
        for(i=0; i<larr-1; ++i)
            for(j=i+1; j<larr; ++j)
                pq.push(Fraction(arr[i], arr[j]));
        for(i=0;i<k-1;++i)
            pq.pop();
        vector<int> res;
        res.push_back(pq.top().num);
        res.push_back(pq.top().den);
        return res;
    }
};
