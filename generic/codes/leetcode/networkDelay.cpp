#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int NArr[101][101];
        int i = 0, j;
        for (; i <= N;++i)
            for(j = 0; j <= N; ++j)
            {
                if (i == j)
                    NArr[i][j] = 0;
                else
                    NArr[i][j] = -1;
            }
        vector<vector<int>>::iterator it = times.begin();
        vector<vector<int>>::iterator eit = times.end();
        
        for(;it!=eit;++it)
            NArr[(*it)[0]][(*it)[1]] = (*it)[2];
        
	int resArr[101];
        for (i=0;i<=N;++i)
            resArr[i] = -1;
        resArr[K] = 0;
       	
        for (i=1;i<=N;++i)
        {
            bool reached = false;
            if (resArr[i] == -1)
                maxDelayTime(NArr, resArr, i, N, reached);
            if (resArr[i] == -1)
		    return -1;
        }
        int res = -1;
        for (i=1;i<=N;++i)
        {
            res = (res > resArr[i]) ? res : resArr[i];
        }
        return res;
    }
private:
    int maxDelayTime(int NArr[101][101], int resArr[101], int pos, int N, bool& reached)
    {
        if (resArr[pos] == -1)
        {
            for(int i = 1; i <= N; ++i)
            {
		if (i == pos)
		   continue;
                if (NArr[i][pos] != -1)
                {
                    int lres = maxDelayTime(NArr, resArr, i, N, reached);
		    if (reached)
		    {
			    if (resArr[pos] == -1)
			    	resArr[pos] = lres + NArr[i][pos];
			    else
			    {
				lres += NArr[i][pos];
				resArr[pos] = (lres >resArr[pos]) ? resArr[pos] : lres;
			    }
		    }
		    reached = false;
                }
            }
        }
	if (resArr[pos] != -1)
	    reached = true;
        return resArr[pos];
    }
};

int main()
{
	vector<vector<int>> times;
	int L, N,K,s,d,w;
	cin >> L >> N >> K;
	for (int i = 0; i < L; ++i)
	{
		cin >> s >> d >> w; 
		vector<int> ob;
		ob.push_back(s);
		ob.push_back(d);
		ob.push_back(w);
		times.push_back(ob);
	}
	Solution obj;
	cout << obj.networkDelayTime(times, N, K) << endl;
	return 0;
}