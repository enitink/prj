#include<iostream>
#include<vector>
#include<map>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = 0;
        for(; i < inorder.size(); i++) {
            inOrderPos[inorder[i]] = i;
        }
        TreeNode* root = nullptr;
        int len = postorder.size();
        for(i=len-1; i>=0; --i){
            if (root == nullptr) {
                root = new TreeNode(postorder[i]);
            } else {
                insertNode(root, postorder[i]);
            }
        }
        return root;
    }
};