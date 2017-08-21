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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> t;
        t.push_back(root);
        vector<int> dep;
        dep.push_back(0);
        vector<int> father;
        father.push_back(0);
        int pos_p, pos_q;
        for(int i=0; i<t.size(); ++i) {
            auto x = t[i];
            if(x == p) pos_p = i;
            if(x == q) pos_q = i;
            if(x->left) {
                dep.push_back(dep[i]+1);
                t.push_back(x->left);
                father.push_back(i);
            }
            if(x->right) {
                dep.push_back(dep[i]+1);
                t.push_back(x->right);
                father.push_back(i);
            }
        }
        if(dep[pos_p] > dep[pos_q]) swap(pos_p, pos_q);
        while(pos_p != pos_q) {
            while(dep[pos_p] < dep[pos_q]) pos_q = father[pos_q];
            if(pos_p != pos_q) {
                pos_p = father[pos_p];
                pos_q = father[pos_q];
            }
        }
        return t[pos_p];
    }
};
