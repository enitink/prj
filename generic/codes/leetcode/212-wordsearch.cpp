#include <iostream>
#include <vector>
#include <string>
#include <map>

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

    ~_trieNode(){
        for (int i=0; i<26; ++i)
        {
            if (childs[i])
            {
                delete childs[i];
                childs[i] = nullptr;
            }
        }
    }
    _trieNode* childs[26];
    bool isEnd;
}trieNode;

class Trie {
public:
    trieNode* root;

    Trie(){
        root = new trieNode;
    }
    ~Trie()
    {
        delete root;
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
};

class Solution {
    private:
    void helper(vector<vector<char> >& board, vector<string>& result, int r, int c, trieNode* node, string word, map<int, bool>& visited) {
        if (node == nullptr)
            return;

        int rows = board.size();
        int cols = board[0].size();
        int pos = r * cols + c;

        if (visited[pos])
            return;

        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;

        char ch = board[r][c];
        node = node->childs[ch - 'a'];
        word += ch;

        if (node == nullptr)
            return;

        visited[pos] = true;

        if (node->isEnd)
        {
            if (find(result.begin(), result.end(), word) == result.end())
                result.push_back(word);
        }

        helper(board, result, r-1, c, node, word, visited);
        helper(board, result, r+1, c, node, word, visited);
        helper(board, result, r, c-1, node, word, visited);
        helper(board, result, r, c+1, node, word, visited);

        visited[pos] = false;
    }
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> result;
        Trie trie;
        for (auto &word : words) {
            trie.insert(word);
        }
        for (int r=0; r<board.size(); ++r)
            for (int c=0; c<board[0].size(); ++c)
            {
                map<int, bool> visited;
                helper(board, result, r, c, trie.root, "", visited);
            }
        return result;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<char> > board = {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'}
        };
        vector<string> words = {"oath","pea","eat","rain"};
        vector<string> result = s.findWords(board, words);
        for (auto &str : result) {
            cout << str << endl;
        }
    }
    {
        vector<vector<char> > board = {
            {'a','b'},
            {'c','d'}
        };
        vector<string> words = {"abcb"};
        vector<string> result = s.findWords(board, words);
        for (auto &str : result) {
            cout << str << endl;
        }
    }
    {
        vector<vector<char> > board = {
            {'a','a'}
        };
        vector<string> words = {"aaa"};
        vector<string> result = s.findWords(board, words);
        for (auto &str : result) {
            cout << str << endl;
        }
    }
    {
        vector<vector<char> > board = {
            {'a','b','c'},
            {'a','e','d'},
            {'a','f','g'}
        };
        vector<string> words = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"};
        vector<string> result = s.findWords(board, words);
        for (auto &str : result) {
            cout << str << endl;
        }
    }
    {
        vector<vector<char> > board = {
            {'o','a','b','n'},
            {'o','t','a','e'},
            {'a','h','k','r'},
            {'a','f','l','v'}
        };
        vector<string> words = {"oa","oaa"};
        vector<string> result = s.findWords(board, words);
        for (auto &str : result) {
            cout << str << endl;
        }   
    }
    return 0;
}