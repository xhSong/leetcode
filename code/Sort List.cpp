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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* h1, *h2;
        cut(head, h1, h2);
        h1 = sortList(h1);
        h2 = sortList(h2);
        return merger(h1, h2);
    }
    
private:
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
    
    ListNode* merger(ListNode* h1, ListNode* h2) {
        ListNode *head, *tail, *p;
        if (h1->val < h2->val) {
            tail = head = h1;
            h1 = h1->next;
        } else {
            tail = head = h2;
            h2 = h2->next;
        }
        while (h1 || h2) {
            if (h1 && h2) {
                if (h1->val < h2->val) {
                    p = h1, h1 = h1->next;
                } else {
                    p = h2, h2 = h2->next;
                }
            } else if (!h1 && h2) {
                p = h2, h2 = h2->next;
            } else if (h1 && !h2) {
                p = h1, h1 = h1->next;
            }
            tail->next = p;
            tail = p;
        }
        tail->next = NULL;
        return head;
    }
};