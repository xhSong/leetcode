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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *newhead = NULL, *p = head, *q;
        while (p) {
            q = p;
            p = p->next;
            insert(newhead, q);
        }
        return newhead;
    }
    
private:
    void insert(ListNode* &head, ListNode *node) {
        node->next = NULL;
        if (head == NULL) {
            head = node;
        } else if (node->val < head->val) {
            node->next = head;
            head = node;
        } else {
            for (ListNode *p = head; p; p = p->next) {
                if (p->next == NULL || p->next->val >= node->val) {
                    node->next = p->next;
                    p->next = node;
                    return ;
                }
            }
        }
    }
};