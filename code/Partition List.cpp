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
    ListNode *partition(ListNode *head, int x) {
        ListNode h1(0), *p1, h2(0), *p2;
        p1 = &h1, p2 = &h2;
        for (ListNode *p3 = head; p3; p3 = p3->next) {
            if (p3->val < x) {
                p1->next = p3;
                p1 = p1->next;
            } else {
                p2->next = p3;
                p2 = p2->next;
            }
        }
        p1->next = h2.next;
        p2->next = NULL;
        return h1.next;
    }
};