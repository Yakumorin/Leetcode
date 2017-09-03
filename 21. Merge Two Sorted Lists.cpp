/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* now1 = l1;
        ListNode* now2 = l2;
        ListNode* head, *now;
        if(l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        now = head;
        while(1) {
            if(!l1) {
                now->next = l2;
                break;
            }
            if(!l2) {
                now->next = l1;
                break;
            }
            if(l1->val <= l2->val) {
                now->next = l1;
                now = l1;
                l1 = l1->next;
            } else {
                now->next = l2;
                now = l2;
                l2 = l2->next;
            }
        }
        return head;
    }
};
