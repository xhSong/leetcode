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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n <= 0) return head;
        ListNode newhead(0), *p, *q = head;
        int diff = 0;
        newhead.next = head;
        p = &newhead;
        for (; q; q = q->next) {
            if (diff == n) {
                p = p->next;
            } else {
                ++ diff;
            }
        }
        q = p->next;
        p->next = q->next;
        delete q;
        return newhead.next;
    }
};