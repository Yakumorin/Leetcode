/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<string> res;
    void go(TreeNode* root, string path) {
        path += to_string(root->val);
        if(!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        if(root->left) go(root->left, path+"->");
        if(root->right) go(root->right, path+"->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        if(root) go(root, "");
        return res;
    }
};
