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
    TreeNode* build(vector<int>& nums, int l, int r) {
        if(l > r) return NULL;
        int mid = (l+r)/2;
        TreeNode* left = build(nums, l, mid-1);
        TreeNode* right = build(nums, mid+1, r);
        TreeNode* now = new TreeNode(nums[mid]);
        now->left = left;
        now->right = right;
        return now;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(!size) return NULL;
        return build(nums, 0, size-1);
    }
};
