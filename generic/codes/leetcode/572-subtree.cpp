#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* subRootCopy;

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if ((subRoot == nullptr) && (root == nullptr))
            return true;

        if (root && subRoot && (root->val == subRoot->val)) 
            return sameTree(root->left, subRoot->left) &&
                        sameTree(root->right, subRoot->right);
        
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr)
            return true;
        if (root == nullptr)
            return false;

        if (sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main()
{
    Solution s;
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);

        TreeNode* subRoot = new TreeNode(4);
        subRoot->left = new TreeNode(1);
        subRoot->right = new TreeNode(2);

        cout << s.isSubtree(root, subRoot) << endl;
    }
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(0);

        TreeNode* subRoot = new TreeNode(4);
        subRoot->left = new TreeNode(1);
        subRoot->right = new TreeNode(2);

        cout << s.isSubtree(root, subRoot) << endl;
    }
    return 0;
}