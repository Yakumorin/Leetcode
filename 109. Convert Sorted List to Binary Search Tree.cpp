/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* node;
    TreeNode* build(int l, int r) {
        if(l > r) return NULL;
        int mid = (l+r)/2;
        TreeNode* left = build(l, mid-1);
        TreeNode* now = new TreeNode(node->val);
        now->left = left;
        node = node->next;
        TreeNode* right = build(mid+1, r);
        now->right = right;
        return now;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        int size = 0;
        ListNode* now = head;
        node = head;
        while(now != NULL) {
            size++;
            now = now->next;
        }
        return build(0, size-1);
    }
};
