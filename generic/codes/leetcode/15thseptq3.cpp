#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct _trieNode
{
    _trieNode() : isEnd(false)
    {
        for (int i=0; i<26; ++i)
        {
            childs[i] = nullptr;
        }
    }

    _trieNode* childs[26];
    bool isEnd;
}trieNode;

class Trie {
private:
    trieNode* root;

public:
    vector<int> memo;

    Trie(){
        root = new trieNode;
    }
    
    void insert(string& word) {
        int wlen = word.size(), i = 0;
        trieNode* lchilds = root;

        for( ; i<wlen; ++i)
        {
            if (lchilds->childs[word[i] - 'a'])
            {
                if (i + 1 == wlen)
                    lchilds->childs[word[i] - 'a']->isEnd = true;
                lchilds = lchilds->childs[word[i] - 'a'];
            }
            else
            {
                break;
            }
        }

        for(;i<wlen; ++i)
        {
            lchilds->childs[word[i] - 'a'] = new trieNode;
            if (i+1 == wlen)
                lchilds->childs[word[i] - 'a']->isEnd = true;
            lchilds = lchilds->childs[word[i] - 'a'];
        }
    }

    int countReq(string& target, int st) {
        int wlen = target.size(), i = st, count = 1;
        if (st >= wlen)
            return 1000000000;
        if (memo[st] != -1 ) {
            return memo[st];
        }
        trieNode* lchilds = root;
        vector<vector<int>> wcount(wlen - st, vector<int>(2, 1000000000));

        for(;i<wlen;++i) {
            if (lchilds->childs[target[i] - 'a'] != nullptr)
            {
                if ((i+1-st) < (wlen-st)) {
                    int res = countReq(target, i+1);
                    wcount[i+1 -st][1] = res == -1 ? 1000000000 : res;
                    wcount[i+1 -st][0] = count;
                }
                lchilds = lchilds->childs[target[i] - 'a'];
                if (i + 1 == wlen)
                    break;
            } else if (root->childs[target[i] - 'a'] != nullptr) {
                lchilds = root->childs[target[i] - 'a'];
                ++count;
            } else {
                return -1;
            }
        }
        wcount[0][0] = count;
        wcount[0][1] = 0;
        for (auto& w: wcount) {
            //cout << st  << " : " << w[0] << " : " << w[1] << " : " << count << " == ";
            if (w[0] + w[1]  < count)
                count = w[0] + w[1];
        }
        //cout << " :: >> "<< count << endl;
        memo[st] = count;
        return count;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        trie.memo.resize(target.size(), -1);
        for (auto& word : words)
            trie.insert(word);
        int result = 0;
        return trie.countReq(target, 0);
    }
};

int main()
{
    Solution ob;
    {
        vector<string> words = {"abc","aaaaa","bcdef"};
        cout << ob.minValidStrings(words, "aabcdabc") << endl;
    }
    {
        vector<string> words = {"abababab","ab"};
        cout << ob.minValidStrings(words, "ababaababa") << endl;
    }
    {
        vector<string> words = {"abcdef"};
        cout << ob.minValidStrings(words, "xyz") << endl;
    }
    {
        // "b","ccacc","a"
        vector<string> words = {"b","ccacc","a"};
        cout << ob.minValidStrings(words, "cccaaaacba") << endl;
    }

    return 0;
}
