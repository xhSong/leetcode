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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return head;
        int n = 1;
        ListNode *tail = head;
        for (; tail->next; tail = tail->next) {
            ++ n;
        }
        tail->next = head;
        k = n - k % n;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};