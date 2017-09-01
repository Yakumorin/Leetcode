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
    bool check(TreeNode* root, long long minr, long long maxr) {
        if(!root) return 1;
        if(root->val < minr || root->val > maxr) return 0;
        if(root->left) if(!check(root->left, minr, root->val-1LL)) return 0;
        if(root->right) if(!check(root->right, root->val+1LL, maxr)) return 0;
        return 1;
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};
