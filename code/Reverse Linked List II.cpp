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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode newhead(0), *pre, *p, *q;
        newhead.next = head;
        pre = &newhead;
        p = head;
        for (int i = 1; i < m; ++i) {
            pre = p, p = p->next;
        }
        for (int i = m; i < n; ++i) {
            q = p->next;
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
        }
        return newhead.next;
    }
};