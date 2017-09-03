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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddhead, *oddnow;
        ListNode* evenhead, *evennow;
        ListNode* now = head;
        oddhead = oddnow = evenhead = evennow = NULL;
        int times = 0;
        while(now != NULL) {
            ++times;
            if(times & 1) {
                if(oddhead == NULL) {
                    oddhead = oddnow = now;
                } else {
                    oddnow->next = now;
                    oddnow = now;
                }
            } else {
                if(!evenhead) {
                    evenhead = evennow = now;
                } else {
                    evennow->next = now;
                    evennow = now;
                }
            }
            now = now->next;
        }
        if(oddhead == NULL) oddhead = evenhead;
        else {
            if(evenhead != NULL) {
                oddnow->next = evenhead;
                evennow->next = NULL;
            }
        }
        return oddhead;
    }
};
