


typedef struct _TreeNode {
    int val;
    _TreeNode *left;
    _TreeNode *right;
    _TreeNode() : val(0), left(nullptr), right(nullptr) {}
    _TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    _TreeNode(int x, _TreeNode *left, _TreeNode *right) : val(x), left(left), right(right) {}
 }TreeNode;
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};