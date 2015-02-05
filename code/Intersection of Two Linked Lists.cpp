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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lena = ListSize(headA);
        size_t lenb = ListSize(headB);
        while (lena && lenb) {
            if (headA == headB) return headA;
            if (lena >= lenb) {
                -- lena;
                headA = headA->next;
            } else {
                -- lenb;
                headB = headB->next;
            }
        }
        return nullptr;
    }
private:
    size_t ListSize(ListNode *head) {
        size_t size = 0;
        while (head) {
            ++ size;
            head = head->next;
        }
        return size;
    }
};