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

typedef struct _tree {
    int val;
    vector<_tree*> childs;
    _tree(int x): val(x) {}
} tree;

class Solution {
    int result;
    set<int> visited;

    void buildTree(tree* root, map<int, vector<int>>& med) {
        for(auto& c:med[root->val]) {
            if(visited.find(c) != visited.end()) continue;
            visited.insert(c);
            tree* child = new tree(c);
            root->childs.push_back(child);
            buildTree(child, med);
        }
    }

    int treeSize(tree* root) {
        if(root == nullptr) return 0;
        int size = root->childs.size();
        if(size == 0) {
            result++;
            return 1;
        }

        vector<int> csizes(size);

        int i = 0;
        for(;i<size;++i){
            csizes[i] = treeSize(root->childs[i]);
        }

        int sum = csizes[0];
        bool allsame = true;
        for(i=1;i<size;++i) {
            if(csizes[i] != csizes[i-1]) {
                allsame = false;;
            }
            sum += csizes[i];
        }
        result += allsame;
        return sum+1;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        map<int, vector<int>> med;
        for(auto& e:edges) {
            med[e[0]].push_back(e[1]);
            med[e[1]].push_back(e[0]);
        }
        tree* root = new tree(0);
        visited.clear();
        visited.insert(0);
        buildTree(root, med);
        result = 0;
        treeSize(root);
        return result;
    }
};

int main() {
    Solution s;
    
    {
        //[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
        vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
        cout << s.countGoodNodes(edges) << endl;
    }
    {
        //[[6,0],[1,0],[5,1],[2,5],[3,1],[4,3]]
        vector<vector<int>> edges = {{6,0},{1,0},{5,1},{2,5},{3,1},{4,3}};
        cout << s.countGoodNodes(edges) << endl;
    }
    {
        //[[1,0],[3,0],[2,3]]
        vector<vector<int>> edges = {{1,0},{3,0},{2,3}};
        cout << s.countGoodNodes(edges) << endl;
    }
    return 0;
}