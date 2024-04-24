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
    int helper(TreeNode* root, int &diameter)
    {
        if (root == nullptr) {
            return 0;
        }
        int lheight = helper(root->left, diameter);
        int rheight = helper(root->right, diameter);
        diameter = max(diameter, lheight + rheight);
        return max(lheight, rheight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int diameter = 0;
        int ldiameter = helper(root->left, diameter);
        int rdiameter = helper(root->right, diameter);

        diameter = max(diameter, ldiameter + rdiameter);
    
        return  diameter;
    }
};

int main()
{
    Solution s;
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        cout << s.diameterOfBinaryTree(root) << endl;
    }
    return 0;
}