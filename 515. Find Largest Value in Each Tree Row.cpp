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
    int maxdeep, maxval[20000];
    void acc(TreeNode* root, int d) {
        if(root == NULL) return;
        if(d > maxdeep) maxdeep = d;
        if(maxval[d] == -1001010107 || root->val > maxval[d]) maxval[d] = root->val;
        acc(root->left, d+1);
        acc(root->right, d+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        maxdeep = -1;
        for(int i=0; i<20000; ++i) maxval[i] = -1001010107;
        acc(root, 0);
        
        vector<int> res;
        for(int i=0; i<=maxdeep; ++i) res.push_back(maxval[i]);
        return res;
    }
};
