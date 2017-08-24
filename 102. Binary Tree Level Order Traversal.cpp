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
    int maxdeep;
    vector<int>maxval[20000];
    void acc(TreeNode* root, int d) {
        if(root == NULL) return;
        if(d > maxdeep) maxdeep = d;
        maxval[d].push_back(root->val);
        acc(root->left, d+1);
        acc(root->right, d+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        maxdeep = -1;
        acc(root, 0);
        
        vector<vector<int>> res;
        for(int i=0; i<=maxdeep; ++i) res.push_back(maxval[i]);
        return res;
    }
};
