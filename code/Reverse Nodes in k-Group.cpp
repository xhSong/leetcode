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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode newhead(0), *pre;
        newhead.next = head;
        pre = &newhead;
        for (ListNode *p = head; p; pre = p, p = p->next) {
            ListNode *tail = p;
            for (int i = 1; i < k && tail; ++i) tail = tail->next;
            if (tail == NULL) break;
            tail = p->next;
            for (int i = 1; i < k; ++i) {
                p->next = tail->next;
                tail->next = pre->next;
                pre->next = tail;
                tail = p->next;
            }
        }
        return newhead.next;
    }
};