#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <bitset>
#include <numeric>
#include <functional>
#include <utility>
#include <limits>
#include <iterator>


using namespace std;

/*
Q2. Hash Divided String
Medium
4 pt.
You are given a string s of length n and an integer k, where n is a multiple of k. Your task is to hash the string s into a new string called result, which has a length of n / k.

First, divide s into n / k 
substrings
, each with a length of k. Then, initialize result as an empty string.

For each substring in order from the beginning:

The hash value of a character is the index of that character in the English alphabet (e.g., 'a' → 0, 'b' → 1, ..., 'z' → 25).
Calculate the sum of all the hash values of the characters in the substring.
Find the remainder of this sum when divided by 26, which is called hashedChar.
Identify the character in the English lowercase alphabet that corresponds to hashedChar.
Append that character to the end of result.
Return result.
*/
class Solution {
public:
    string stringHash(string s, int k) {
        int l = s.length();
        string result = "";
        int h = 0, m = 1;
        for(int i = 1; i<=l; ++i) {
            h += s[i-1] - 'a';
            if (i == k*m) {
                m++;
                result += ('a' + h%26);
                h = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.stringHash("abcd", 2) << endl;
    cout << s.stringHash("mxz", 3) << endl;
    return 0;
}