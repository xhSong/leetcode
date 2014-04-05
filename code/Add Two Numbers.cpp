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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        ListNode head(0), *p;
        int c = 0;
        p = &head;
        while(l1 || l2) {
            if (l1) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                c += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(c % 10);
            p = p->next;
            c /= 10;
        }
        if (c) {
            p->next = new ListNode(c);
        }
        return head.next;
    }
};