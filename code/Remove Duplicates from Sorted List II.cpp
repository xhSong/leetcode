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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode newhead(0);
        newhead.next = head;
        
        ListNode *pre = &newhead, *p = head;
        while (p && p->next) {
            bool needdelete = false;
            while(p->next && p->val == p->next->val) {
                p->next = p->next->next;
                needdelete = true;
            }
            if (needdelete) {
                pre->next = p->next;
                p = pre->next;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return newhead.next;
    }
};