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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return head;
        ListNode *p = head, *q;
        while(p->next) {
            if (p->val == p->next->val) {
                q = p->next;
                p->next = q->next;
                delete q;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};