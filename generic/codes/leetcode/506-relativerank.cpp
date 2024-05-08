class ScoreData {
public:
    ScoreData(int sc, int p) : score(sc), pos(p) {}
    int score;
    int pos;
};

class Compare {
public:
    bool operator()(ScoreData below, ScoreData above)
    {
        return below.score < above.score;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<ScoreData, vector<ScoreData>, Compare> pdata;
        int i;
        for(i = 0; i< score.size(); ++i) {
            pdata.push(ScoreData(score[i], i));
        }
        vector<string> result;
        result.resize(score.size());
        
        string position[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        i = 0;
        while(!pdata.empty())
        {
            if (i < 3)
                result[pdata.top().pos] = position[i];
            else
                result[pdata.top().pos] = std::to_string(i+1);
            ++i;
            pdata.pop();
        }
        return result;
    }
};