/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void go_serialize(TreeNode* root, string &res) {
        if(!root) {
            res += "null,";
            return;
        }
        res += to_string(root->val) + ',';
        go_serialize(root->left, res);
        go_serialize(root->right, res);
    }
    
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        go_serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* go_deserialize(string &data, int &k) {
        int t = data.find(",", k);
        string val = data.substr(k, t-k);
        k = t+1;
        if(val == "null") return NULL;
        TreeNode* now = new TreeNode(stoi(val));
        now->left = go_deserialize(data, k);
        now->right = go_deserialize(data, k);
        return now;
    }
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        int k = 0;
        TreeNode* root = go_deserialize(data, k);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
