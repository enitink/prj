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
 
class Solution {
    int helper(TreeNode *root, int& maxsum)
    {
        if (nullptr == root)
            return 0;
        int left = helper(root->left, maxsum);
        int right = helper(root->right, maxsum);
        int max = (left > right) ? left : right;
        int lmaxsum = left + right + root->val;
        if (lmaxsum < root->val)
            lmaxsum = root->val;
        if (lmaxsum < left + root->val)
            lmaxsum = left + root->val;
        if (lmaxsum < right + root->val)
            lmaxsum = right + root->val;
        if (lmaxsum > maxsum)
            maxsum = lmaxsum;
        return (max + root->val > root->val) ? max + root->val : root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (nullptr == root)
            return 0;
        int maxsum = -1001;
        int retmax = helper(root, maxsum);
        return retmax > maxsum ? retmax : maxsum;
    }
};

int main()
{
    Solution sol;
    /*{
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        cout << "Max Path Sum: " << sol.maxPathSum(root) << endl;
    }
    {
        TreeNode *root = new TreeNode(-10);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        cout << "Max Path Sum: " << sol.maxPathSum(root) << endl;
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(7);
        cout << "Max Path Sum: " << sol.maxPathSum(root) << endl;
    }
    {
        TreeNode *root = new TreeNode(-1); 
        root->left = new TreeNode(-2);
        root->right = new TreeNode(10);   
        root->right->left = new TreeNode(-6);
        root->right->right = new TreeNode(-3);
        root->right->right->left = new TreeNode(-6);
        cout << "Max Path Sum: " << sol.maxPathSum(root) << endl;
    }*/
    {
        TreeNode *root = new TreeNode(9);
        root->left = new TreeNode(6);
        root->right = new TreeNode(-3);
        root->right->left = new TreeNode(-6);
        root->right->right = new TreeNode(2);
        root->right->right->left = new TreeNode(2);
        root->right->right->left->right = new TreeNode(-6);
        root->right->right->left->left = new TreeNode(-6);
        root->right->right->left->left->left = new TreeNode(-6);
        cout << "Max Path Sum: " << sol.maxPathSum(root) << endl;
    }
    return 0;

}