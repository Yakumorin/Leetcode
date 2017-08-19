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
    vector<vector<int>> res;
    void go(TreeNode* root, int sum, vector<int> now) {
        sum -= root->val;
        now.push_back(root->val);
        if(sum == 0) {
            if(!root->left && !root->right) res.push_back(now);
        }
        if(root->left) go(root->left, sum, now);
        if(root->right) go(root->right, sum, now);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        if(root) go(root,sum, tmp);
        return res;
    }
};
