#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct _trieNode
{
    _trieNode() : count(0)
    {
        for (int i=0; i<26; ++i)
        {
            childs[i] = nullptr;
        }
    }

    _trieNode* childs[26];
    int count;
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
                    lchilds->childs[word[i] - 'a']->count += 1;
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
                lchilds->childs[word[i] - 'a']->count += 1;
            lchilds = lchilds->childs[word[i] - 'a'];
        }
    }
    
    int search(string word) {
        int wlen = word.size(), i = 0;
        if ((root == nullptr) || (wlen == 0))
            return 0;

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
                return 0;
        }

        return lchilds->count;
    }
};

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        Trie* obj = new Trie();
        vector<string>::iterator it = words.begin();
        vector<string>::iterator eit = words.end();
        for( ; it != eit; ++it)
        {
            obj->insert(*it);
        }
        int slen = s.length(), i = 1, result = 0;
        for( ; i<=slen; ++i)
        {
            string sub = s.substr(0, i);
            result += obj->search(sub);
        }
        delete obj;
        return result;
    }
};

int main()
{
    // words = ["a","b","c","ab","bc","abc"], s = "abc"
    vector<string> words;
    words.push_back("a"); words.push_back("b");
    words.push_back("c"); words.push_back("ab"); 
    words.push_back("bc"); words.push_back("abc");

    Solution ob;
    cout << ob.countPrefixes(words, "abc") << endl;

    vector<string> words1;
    words1.push_back("a");
    words1.push_back("a");

    cout << ob.countPrefixes(words1, "aa") << endl;
    cout << ob.countPrefixes(words1, "ba") << endl;



    return 0;
}
