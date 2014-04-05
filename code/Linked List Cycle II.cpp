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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> pset;
        for (ListNode *p = head; p; p = p->next) {
            if (pset.find(p) != pset.end()) {
                return p;
            }
            pset.insert(p);
        }
        return NULL;
    }
};