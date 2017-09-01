/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* temp;
    bool check(ListNode* now) {
        if(now == NULL) return 1;
        bool ok = check(now->next) && temp->val == now->val;
        temp = temp->next;
        return ok;
    }
public:
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
};
