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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (nullptr == root)
            return result;

        vector<TreeNode*> child;
        child.push_back(root);
        helper(result, child);
        
        return result;
    }
    
    void helper(vector<int>& result, vector<TreeNode*> child)
    {
        vector<TreeNode*>::iterator itr = child.begin();
        vector<TreeNode*> newchild;
        
        for( ; itr != child.end(); ++itr)
        {
            if ((*itr)->left)
                newchild.push_back((*itr)->left);
            if ((*itr)->right)
                newchild.push_back((*itr)->right);
        }
        
        result.push_back((*child.back()).val);
        if (!newchild.empty())
            helper(result, newchild);
        
        return;
    }
};