

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int helper(TreeNode* root, int k, int& c)
    {
        if (root == nullptr)
            return 0;
        int result = helper(root->left, k, c);
        if (result)
            return result;
        ++c;
        if (k == c)
            return root->val;
        result = helper(root->right, k, c);
        return result;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        return helper(root, k, c);
    }
};