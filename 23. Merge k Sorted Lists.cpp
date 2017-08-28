/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct compare{
    bool operator()(const ListNode* x, const ListNode* y) {
        return x->val > y->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> hp;
        for(auto x: lists)
            if(x) hp.push(x);
        if(hp.empty()) return NULL;
        ListNode* head = hp.top();
        hp.pop();
        if(head->next) hp.push(head->next);
        ListNode* now = head;
        while(!hp.empty()) {
            now->next = hp.top();
            hp.pop();
            now = now->next;
            if(now->next) hp.push(now->next);
        }
        return head;
    }
};
