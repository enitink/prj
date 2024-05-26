#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        int slen = word.size(), i;
        string result;
        for(i=0;i<slen;++i){
            int count = 1;
            while((i<slen-1) && (word[i] == word[i+1])) {
                count++;
                i++;
                if (count == 9)
                    break;
            }
            result += std::to_string(count);
            result += word[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    {
        string word = "aaabcccd";
        cout << s.compressedString(word) << endl;
    }
    {
        string word = "aaaaaaaaaaaaaabb";
        cout << s.compressedString(word) << endl;
    }
    {
        string word = "abbbbbbbbbbbb";
        cout << s.compressedString(word) << endl;
    }
    {
        string word = "aaaaaaaaaaaaaaaaa";
        cout << s.compressedString(word) << endl;
    }
    return 0;
}