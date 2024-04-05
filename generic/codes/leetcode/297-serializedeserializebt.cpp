#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Codec {
    void helperSerializer(TreeNode* root, string& ser)
    {
        if (root == nullptr)
        {
            ser += "null";
            return;
        }
        ser += ((char)root->val + '0');
        ser += ",";
        helperSerializer(root->left, ser);
        ser += ",";
        helperSerializer(root->right, ser);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        helperSerializer(root, result);
        cout << result;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));