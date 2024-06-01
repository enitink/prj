#include <iostream>
#include <vector>
#include <queue>

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
    int leftHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + leftHeight(root->left);
    }

public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int height = leftHeight(root);
        int total = (1 << height) - 1;

        queue<TreeNode*> q;
        q.push(root);
        queue<TreeNode*> lq;
        int count = 1;
        while(!q.empty()){
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if (root->right)
                    lq.push(node->right);
                if (root->left)
                    lq.push(node->left);
            }
            count *= 2;
            if (count != lq.size()) {

            }
        }

        return total;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    cout << sol.countNodes(root) << endl;

    return 0;
}