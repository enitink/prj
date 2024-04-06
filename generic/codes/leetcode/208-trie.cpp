#include <iostream>
#include <string>

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
    
    bool startsWith(string prefix) {
        int wlen = prefix.size(), i = 0;
        if ((root == nullptr) || (wlen == 0))
            return false;

        trieNode* lchilds = root;
        for(; i<wlen; ++i)
        {
            if (lchilds->childs[prefix[i] - 'a'] != nullptr)
            {
                lchilds = lchilds->childs[prefix[i] - 'a'];
                if (i + 1 == wlen)
                   return true;
            }
            else
                return false;
        }
        // This will never reach
        return false;
    }
};

int main()
{
    Trie* obj = new Trie();
    cout << obj->search("apple") << endl;
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->startsWith("app") <<endl ;
    cout << obj->search("app") <<endl ;
    obj->insert("app");
    cout << obj->startsWith("app") <<endl ;
    cout << obj->search("app") <<endl ;
    cout << obj->search("x") << endl;
    cout << obj->startsWith(("y")) << endl;

    return 0;
}
