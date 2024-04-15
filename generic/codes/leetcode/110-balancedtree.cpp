#include <iostream>
#include <cmath>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int ldepth = 0, rdepth = 0;
        bool ltree = helper(root->left, ldepth);
        if (!ltree)
            return false;
        bool rtree = helper(root->right, rdepth);
        if (!rtree)
            return false;

        int depth = abs(ldepth - rdepth);

        if (depth > 1)
            return false;

        return true;
    }

    bool helper(TreeNode* root, int& depth){
        if (root == nullptr)
        {
            depth = 1;
            return true;
        }

        int ldepth = 0, rdepth = 0;
        bool ltree = helper(root->left, ldepth);
        if (!ltree)
            return false;
        bool rtree = helper(root->right, rdepth);
        if (!rtree)
            return false;

        depth = abs(ldepth - rdepth);

        if (depth > 1)
            return false;

        depth = (ldepth > rdepth) ? ldepth + 1 : rdepth + 1;
        
        return true;
    }
};