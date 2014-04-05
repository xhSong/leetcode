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
    ListNode *swapPairs(ListNode *head) {
        ListNode newhead(0);
        newhead.next = head;
        for (ListNode *p = head, *pre = &newhead; p && p->next; pre = p, p = p->next) {
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = p;
        }
        return newhead.next;
    }
};