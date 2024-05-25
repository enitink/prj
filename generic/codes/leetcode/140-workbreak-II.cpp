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
    Trie(){
        root = new trieNode;
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        int wlen = word.size(), i = 0;
        if ((root == nullptr) || (wlen == 0))
            return false;

        trieNode* lchilds = root;
        for(; i<wlen; ++i)
        {
            if (lchilds->childs[word[i] - 'a'] != nullptr)
            {
                lchilds = lchilds->childs[word[i] - 'a'];
                if (i + 1 == wlen)
                    break;
            }
            else
                return false;
        }
        return lchilds->isEnd;
    }
};


class Solution {
private:
    void helper(string& s, Trie* obj, int st, string& res, vector<string>& result) {
        if (st == s.size()) {
            result.push_back(res.substr(0, res.size()-1));
            return;
        }
        for (int i = st; i < s.size(); ++i) {
            string sub = s.substr(st, i - st + 1);
            if (obj->search(sub)) {
                res += sub;
                res += " ";
                helper(s, obj, i+1, res, result);
                res.pop_back(); //remove space
                for (auto ch : sub)
                    res.pop_back(); //remove complete word
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        Trie* obj = new Trie();
        for (auto word : wordDict) {
            obj->insert(word);
        }
        string res;
        helper(s, obj, 0, res, result);
        return result;
    }
};

int main() {
    Solution s;
    {
        string str = "catsanddog";
        vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
        vector<string> result = s.wordBreak(str, wordDict);
        for (auto res : result) {
            cout << res << endl;
        }
    }
    return 0;
}