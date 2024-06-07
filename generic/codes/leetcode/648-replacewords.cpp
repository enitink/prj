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
    
    void insert(string& word) {
        int wlen = word.size(), i = 0;
        trieNode* lchilds = root;

        for( ; i<wlen; ++i) {
            if (lchilds->childs[word[i] - 'a']) {
                if (i + 1 == wlen)
                    lchilds->childs[word[i] - 'a']->isEnd = true;
                lchilds = lchilds->childs[word[i] - 'a'];
            }
            else {
                break;
            }
        }

        for(;i<wlen; ++i) {
            lchilds->childs[word[i] - 'a'] = new trieNode;
            if (i+1 == wlen)
                lchilds->childs[word[i] - 'a']->isEnd = true;
            lchilds = lchilds->childs[word[i] - 'a'];
        }
    }
    
    void search(string& word, string& path) {
        int wlen = word.size(), i = 0;
        if ((root == nullptr) || (wlen == 0))
            return;

        trieNode* lchilds = root;
        bool isend = false;
        for(; i<wlen; ++i) {
            if (lchilds->childs[word[i] - 'a'] != nullptr) {
                lchilds = lchilds->childs[word[i] - 'a'];
                isend = lchilds->isEnd;
                path += word[i];
                if (isend)
                    return;
            }
            else {
                break;
            }
        }
        if (!isend)
            path = "";
        return;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie tr;
        for(auto& s : dictionary) {
            tr.insert(s);
        } 
        stringstream ss(sentence);
        string token;
        string result;
        while (getline(ss, token, ' ')) {
            string path;
            tr.search(token, path);
            if (!result.empty())
                result += ' ';
            if (!path.empty())
                result += path;
            else
                result += token;
        }

        return result;
    }
};