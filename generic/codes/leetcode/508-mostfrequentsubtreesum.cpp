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
    map<int, int> freqmap;

    int helper(TreeNode* root)
    {
        if ((root->left == nullptr) && (root->right == nullptr)) {
            if (freqmap.find(root->val) != freqmap.end())
                freqmap[root->val]++;
            else 
                freqmap[root->val] = 1;
            return root->val;
        }
        int lsum = 0, rsum = 0;
        if (root->left){
            lsum = helper(root->left);
        }
        if (root->right) {
            rsum = helper(root->right);
        }
        rsum = rsum + root->val + lsum;
        if (freqmap.find(rsum) != freqmap.end())
            freqmap[rsum]++;
        else 
            freqmap[rsum] = 1;

        return rsum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if ((root->left == nullptr) && (root->right == nullptr))
            return vector<int>{root->val};
        helper(root);
        int max = 0;
        map<int,int>::iterator itr = freqmap.begin();
        map<int,int>::iterator eitr = freqmap.end();
        map<int, vector<int>> resultmap;
        for(;itr!=eitr;++itr) {
            //cout << itr->first << ":" << itr->second << endl;
            if (resultmap.find(itr->second) != resultmap.end())
                resultmap[itr->second].push_back(itr->first);
            else {
                vector<int> l = {itr->first};
                resultmap[itr->second] = l;
            }
            if (itr->second > max) 
                max = itr->second;
        }
        return resultmap[max];
    }
};