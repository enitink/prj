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

class WordDictionary {
private:
    trieNode* root;

public:
    WordDictionary(){
        root = new trieNode;
    }
    
    void addWord(string word) {
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
        return serachInternal(word, root);
    }

    bool serachInternal(string word, trieNode* root)
    {
        int wlen = word.size(), i = 0;
        if (wlen == 0)
            return true;
        if (root == nullptr)
            return false;

        trieNode* lchilds = root;
        for(; i<wlen; ++i)
        {
            // if word[i] is . then call search again with all the present values
            if (word[i] == '.')
            {
                string lword = word.substr(i + 1, wlen - 1 - i);
                int lwlen = lword.size();
                for (int j = 0; j < 26; ++j)
                {
                    if ((lchilds->childs[j]) && (serachInternal(lword, lchilds->childs[j])))
                        return true;
                }
                return false;
            }
            else if (lchilds->childs[word[i] - 'a'] != nullptr)
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

int main()
{
    WordDictionary* obj = new WordDictionary();
    /*obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    obj->addWord("ab");

    cout << obj->search("a.") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search(".ad") <<endl ;
    cout << obj->search("b..") << endl;
    cout << obj->search("x") << endl;
    cout << obj->search("..x") << endl;
    cout << obj->search("...") << endl;
    cout << obj->search("....") << endl << endl;

    obj->addWord("a");
    obj->addWord("a");
    
    //["."],["a"],["aa"],["a"],[".a"],["a."]]
    cout << obj->search(".") << endl;
    cout << obj->search("a") << endl;
    cout << obj->search("aa") << endl;
    cout << obj->search("a") << endl;
    cout << obj->search(".a" ) << endl;
    cout << obj->search("a." ) << endl << endl;*/

    obj->addWord("at");
    obj->addWord("and");
    obj->addWord("an");
    obj->addWord("add");

    //["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]
    cout << obj->search("a") << endl;
    cout << obj->search(".at") << endl;
    
    obj->addWord("bat");

    cout << obj->search(".at") << endl;
    cout << obj->search("an.") << endl;
    cout << obj->search("a.d.") << endl;
    cout << obj->search("b.") << endl;
    cout << obj->search("a.d") << endl;
    cout << obj->search(".") << endl;

    return 0;
}
