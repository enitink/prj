
#include <iostream>

using namespace std;

//Definition for a binary tree node.
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
    Solution(): lastVal(nullptr) {}
    
    bool isValidBST(TreeNode* root)
    {
        if (!root || ((!root->left)&&(!root->right)) )
            return true;
        return isValidBST(root, 0);
    }
    
    bool isValidBST(TreeNode* root, int height) {
        if (!root)
            return (height) ? true : false;
        
        bool valid = isValidBST(root->left, height+1);
        
        //printf("%d %d :", lastVal->val, root->val);
        
        if ( !valid || ((lastVal) && (root->val <= lastVal->val)) )
            return false;
        
        lastVal = root;
        
        return isValidBST(root->right, height+1);
    }
    TreeNode* lastVal;
};