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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        vector<int> sum, base, fa;
        vector<TreeNode*> q;
        q.push_back(root);
        fa.push_back(0);
        int h = 0;
        while(h < q.size()) {
            TreeNode* now = q[h];
            sum.push_back(1);
            if(now->left) {
                q.push_back(now->left);
                fa.push_back(h);
            }
            if(now->right) {
                q.push_back(now->right);
                fa.push_back(h);
            }
            h++;
        }
        res.resize(h);
        for(int i=h-1; i>0; --i)
            sum[fa[i]] += sum[i];
        
        h = 0; q.clear(); q.push_back(root); base.push_back(0);
        while(h < q.size()) {
            TreeNode* now = q[h];
            int now_base = base[h];
            if(now->left) {
                q.push_back(now->left);
                base.push_back(now_base);
                now_base += sum[q.size()-1];
            }
            res[now_base++] = now->val;
            if(now->right) {
                q.push_back(now->right);
                base.push_back(now_base);
            }
            h++;
        }
        return res;
    }
};
