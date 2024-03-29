#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mymap;
        vector<string>::const_iterator sitr = strs.begin();
        vector<string>::const_iterator esitr = strs.end();
        
        for( ; sitr != esitr; ++sitr)
        {
            int slen = (*sitr).length(), i = 0;
            string val("00000000000000000000000000");
            for ( ; i<slen; ++i)
            {
                int index = (*sitr)[i] - 'a';
                int nval = val[index] + 1;
                val[index] = (char)nval;
            }
            if (mymap.find(val) != mymap.end())
            {
                mymap[val].push_back(*sitr);
            }
            else
            {
                vector<string> local;
                local.push_back(*sitr);
                mymap[val] = local;
            }
        }
        
        vector<vector<string> > result;
        map<string, vector<string> >::const_iterator itr = mymap.begin();
        map<string, vector<string> >::const_iterator eitr = mymap.end();

        for( ; itr != eitr; ++itr)
        {
            result.push_back(itr->second); 
        }

        return result;
    }
};

int main()
{
    {
        string inputs[] = {"eat","tea","tan","ate","nat","bat"};
        vector<string> strs(inputs, inputs + 6);
        Solution ob;
        vector<vector<string> > results = ob.groupAnagrams(strs);
        vector<vector<string> >::const_iterator itr = results.begin();
        vector<vector<string> >::const_iterator eitr = results.end();
        cout << "[";
        for( ; itr != eitr; ++itr)
        {
            vector<string>::const_iterator sitr = (*itr).begin();
            vector<string>::const_iterator esitr = (*itr).end();
            cout << "[";
            for( ; sitr != esitr; ++sitr)
            {
                cout << "\"" << *sitr << "\",";
            }
            cout << "], ";
        }
        cout << "]" << endl;
    }
    return 0;
}