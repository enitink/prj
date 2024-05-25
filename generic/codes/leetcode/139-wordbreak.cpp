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
    bool helper(string& s, Trie* obj, int st, string& res) {
        if (st == s.size()) {
            return true;
        }
        for (int i = st; i < s.size(); ++i) {
            string sub = s.substr(st, i - st + 1);
            string lastRes = "";
            if (obj->search(sub)) {
                lastRes += sub;
                lastRes += " ";
            }
            if (lastRes.empty())
                return false;
            res += lastRes;
            res += "";
            if (helper(s, obj, i+1, res))
                    return true;
            res.pop_back();
            for (auto ch : lastRes)
                res.pop_back();
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* obj = new Trie();
        for (auto word : wordDict) {
            obj->insert(word);
        }
        string res;
        return helper(s, obj, 0, res);
    }
};

int main()
{
    Solution S;
    {
        vector<string> wordDict = {"leet", "code"};
        cout << S.wordBreak("leetcode", wordDict) << endl;
    }
    {
        vector<string> wordDict = {"apple", "pen"};
        cout << S.wordBreak("applepenapple", wordDict) << endl;
    }
    {
        vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        cout << S.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict) << endl;
    }
    return 0;
}