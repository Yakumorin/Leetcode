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
    int ans;
    int goTree(TreeNode* root) {
        if(!root) return 0;
        int x = root->val;
        int l = max(0, goTree(root->left)), r = max(0, goTree(root->right));
        ans = max(ans, x+l+r);
        return max(l, r) + x;
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = -1000000000;
        goTree(root);
        return ans;
    }
};
