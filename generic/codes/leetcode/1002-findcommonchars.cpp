class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int freq1[26] = {};
        int freq2[26], i = 0;
        for(;i<26;++i){
            freq2[i] = 1000;
        }
        
        for(auto s : words) {
            for (auto c : s) {
                freq1[c-'a']++;
            }
            for(i=0;i<26;++i){
                freq2[i] = freq1[i] < freq2[i] ? freq1[i] : freq2[i];
                freq1[i] = 0;
            }
        }
        vector<string> result;
        for(i=0;i<26;++i){
            while(freq2[i]) {
                string s(1, (char)(i + 'a'));
                result.push_back(s);
                freq2[i]--;
            }
        }
        return result;
    }
};