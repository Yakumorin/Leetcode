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
    int co;
    vector<int> total;
    int sum(TreeNode* root) {
        if(!root) return 0;
        int x, num;
        x = co++;
        total.push_back(0);
        num = sum(root->left) + sum(root->right) + 1;
        total[x] = num;
        return num;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        co = 0;
        sum(root);
        TreeNode* now = root;
        int node = 0;
        while(1) {
            int x = 0;
            if(!now->left) x = 0;
            else x = total[node + 1];
            if(x >= k) {
                now = now->left;
                node = node + 1;
            } else {
                if(!now->right || x+1 == k) return now->val;
                else {
                    now = now->right;
                    k -= x+1;
                    node = node + x + 1;
                }
            }
        }
    }
};
