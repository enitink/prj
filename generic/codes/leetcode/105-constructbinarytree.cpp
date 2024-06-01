
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    map<int, int> inOrderPos;
    bool insertNode(TreeNode* root, int data) {
        if (inOrderPos[data] < inOrderPos[root->val]) {
            if (root->left)
                return insertNode(root->left, data);
            else {
                root->left = new TreeNode(data);
                return true;
            } 
        } else {
            if (root->right)
                return insertNode(root->right, data);
            else {
                root->right = new TreeNode(data);
                return true;
            }
        }
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inOrderPos[inorder[i]] = i;
        }
        TreeNode* root = nullptr;

        for(auto& data : preorder){
            if (root == nullptr) {
                root = new TreeNode(data);
            } else {
                insertNode(root, data);
            }
        }
        return root;
    }
};