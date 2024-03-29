#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class FrequencyData {
public:
    FrequencyData(char d, int f): data(d), frequency(f) {}
    FrequencyData(): data(0), frequency(0) {}
    char data;
    int frequency;
};

class Compare {
public:
    bool operator()(FrequencyData below, FrequencyData above)
    {
        if (below.frequency < above.frequency) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mymap;
        int slen = s.length(), i = 0;
        for( ; i<slen; ++i)
        {
            if (mymap.find(s[i]) != mymap.end())
            {
                mymap[s[i]]++;
            }
            else
                mymap[s[i]] = 1;
        }
        priority_queue<FrequencyData, vector<FrequencyData>, Compare> pq;
        map<char, int>::const_iterator itr = mymap.begin();
        map<char, int>::const_iterator eitr = mymap.end();
        for ( ; itr != eitr; ++itr)
        {
            FrequencyData ob(itr->first, itr->second);
            pq.push(ob);
        }
        string result;
        while(!pq.empty())
        {
            FrequencyData ob = pq.top();
            pq.pop();
            while(ob.frequency)
            {
                result += ob.data;
                ob.frequency--;
            }
        }
        return result;
    }
};

int main()
{
    Solution ob;

    {
        string s = "tree";
        cout << ob.frequencySort(s) << endl;
    }
    {
        string s = "cccaaa";
        cout << ob.frequencySort(s) << endl;;
    }
    {
        string s = "Aabb";
        cout << ob.frequencySort(s) << endl;;
    }
    {
        string s = "Aabb12";
        cout << ob.frequencySort(s) << endl;;
    }

    return 0;
}