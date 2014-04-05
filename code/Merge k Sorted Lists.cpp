/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct Pointer {
    ListNode *p;
    Pointer() {}
    Pointer(ListNode *p): p(p) {} 
    bool operator < (const Pointer &other) const {
        if (p && other.p) return p->val > other.p->val;
        return p < other.p;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<Pointer> que;
        ListNode head(0), *tail;
        tail = &head;
        for (int i = 0; i < lists.size(); ++i) {
            que.push(Pointer(lists[i]));
        }
        while(!que.empty()) {
            Pointer now = que.top();
            que.pop();
            if (now.p) {
                tail->next = now.p;
                tail = tail->next;
                que.push((now.p)->next);
            }
        }
        return head.next;
    }
};