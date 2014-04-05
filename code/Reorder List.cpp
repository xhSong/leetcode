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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) return;
        
        ListNode *h1, *h2;
        cut(head, h1, h2);
        h2 = reverse(h2);
        for (ListNode *p, *q; h2; h1 = p, h2 = q) {
            p = h1->next;
            q = h2->next;
            h1->next = h2;
            h2->next = p;
        }
    }
private:
    ListNode *reverse(ListNode *head) {
        ListNode *p1 = NULL, *p2 = head, *p3;
        for (; p2; p1 = p2, p2 = p3) {
            p3 = p2->next;
            p2->next = p1;
        }
        return p1;
    }
    void cut(ListNode *head, ListNode* &h1, ListNode* &h2) {
        ListNode* p;
        p = h1 = h2 = head;
        for (int i = 0; p != NULL; ++i, p = p->next) {
            if (i && i % 2 == 0) {
                h2 = h2->next;
            }
        }
        p = h2, h2 = h2->next, p->next = NULL;
    }
};