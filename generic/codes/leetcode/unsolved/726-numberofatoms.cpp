#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    int expand(string& formula, int index) {
        string lastele;
        int lastnum = 0;
        int st = index;
        map<string, int> elemap;
        while((index < formula.size()) && (formula[index] != ')')) {
            if (formula[index] == '(') {
                index = expand(formula, index + 1);
            } else if (((formula[index] - '0') <= 9) && ((formula[index] - '0') >= 0)) { // numbers
                lastnum = (lastnum*10) + (int)(formula[index] - '0');
            } else if (!(formula[index] & 32)) { // capital letter
                if (lastele.length()){
                    if (elemap.find(lastele)  != elemap.end() && elemap[lastele] == 0)
                        elemap[lastele] = 1;
                    elemap[lastele] += lastnum;
                    cout << lastele << " : " << elemap[lastele] << endl;
                }
                lastele = "";
                lastnum = 0;
                lastele += formula[index];
            } else if (formula[index] & 32) { // small letter
                lastele += formula[index];
            }
            ++index;
        }
        if (lastele.length()){
            elemap[lastele] += lastnum;
        }
        ++index;
        lastnum = 0;
        while ((index < formula.size()) 
            && ((formula[index] - '0') <= 9)
            && ((formula[index] - '0') >= 0)) {
                lastnum = (lastnum*10) + (int)(formula[index] - '0');
                ++index;
        }
        string result;
        for(auto& ele:elemap) {
            if(lastnum) {
                if (ele.second)
                    ele.second *= lastnum;
                else
                    ele.second = lastnum;
            }
            if (ele.second)
                result += (ele.first + to_string(ele.second));
            else
                result += ele.first;
        }
        formula.replace(st, index - st, result);
        cout << formula << endl;
        return st - 1;
    }
public:
    string countOfAtoms(string formula) {
        expand(formula, 0);
        return formula;
    }
};

int main() {
    Solution s;
    //cout << s.countOfAtoms("H2O") << endl;
    //cout << s.countOfAtoms("Mg(OH)2") << endl;
    //cout << s.countOfAtoms("K4(ON(SO3)2)2") << endl;
    //cout << s.countOfAtoms("(H2O)") << endl;
    //cout << s.countOfAtoms("(Mg(OH)2)") << endl;
    //cout << s.countOfAtoms("(K4(ON(SO3)2)2)") << endl;
    //cout << s.countOfAtoms("(H2O)3") << endl;
    //cout << s.countOfAtoms("(Mg(OH)2)3") << endl;
    //cout << s.countOfAtoms("(K4(ON(SO3)2)2)3") << endl;
    //cout << s.countOfAtoms("(B2O39He17BeBe49)3") << endl;
    cout << s.countOfAtoms("OHMg(OH)2") << endl;
    return 0;
}