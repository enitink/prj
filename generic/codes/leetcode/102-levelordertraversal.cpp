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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root != nullptr)
        {
            vector<TreeNode*> nodes;
            nodes.push_back(root);
            helper(nodes, result);
        }
        return result;
    }

    void helper(vector<TreeNode*> nodes, vector<vector<int>>& result)
    {
        if (nodes.empty())
            return;
        vector<TreeNode*>::iterator itr = nodes.begin();
        vector<TreeNode*>::iterator eitr = nodes.end();
        vector<int> levelNodesVal;
        vector<TreeNode*> lNodes;
        for( ; itr != eitr; ++itr)
        {
            if ((*itr) == nullptr)
                continue;
            levelNodesVal.push_back((*itr)->val);
            lNodes.push_back((*itr)->left);
            lNodes.push_back((*itr)->right);
        }
        if (levelNodesVal.size())
        {
        result.push_back(levelNodesVal);
        helper(lNodes, result);
        }
    }
};