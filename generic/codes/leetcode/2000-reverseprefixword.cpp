#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;
        int wlen = word.length();
        int i = 0;
        for(;i<wlen;++i){
            st.push(word[i]);
            if(word[i] == ch)
                break;
        }
        if (i < wlen){
            i = 0;
            while(!st.empty())
            {
                word[i] = st.top();
                ++i;
                st.pop();
            }
        }
        return word;
    }
};

int main() {
    Solution sol;

    cout << sol.reversePrefix( "abcdef", 'd') << endl;
    cout << sol.reversePrefix( "xyxzxe", 'z') << endl;
    cout << sol.reversePrefix( "abcd", 'z') << endl;
    
    return 0;
}