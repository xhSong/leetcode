/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        vector<RandomListNode*> nodes;
        RandomListNode head2(0), *tail2 = &head2;
        for (RandomListNode *p = head; p; p = p->next) {
            nodes.push_back(p);
        }
        for (RandomListNode* node: nodes) {
            tail2->next = new RandomListNode(node->label);
            tail2 = tail2->next;
            node->next = tail2;
            tail2->random = node->random;
        }
        for (RandomListNode *p = head2.next; p; p = p->next) {
            if (p->random) p->random = p->random->next;
        }
        for (int i = 0; i < int(nodes.size()) - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }
        if (nodes.size()) nodes[nodes.size() - 1]->next = nullptr;
        return head2.next;
    }
};