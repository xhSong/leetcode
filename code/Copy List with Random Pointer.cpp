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
        map<RandomListNode*, RandomListNode*> keyword;
        keyword[NULL] = NULL;
        RandomListNode newhead(0), *tail;
        tail = &newhead;
        for (RandomListNode *p = head; p; p = p->next) {
            tail->next = new RandomListNode(p->label);
            tail = tail->next;
            keyword[p] = tail;
        }
        for (RandomListNode *p = head; p; p = p->next) {
            keyword[p]->random = keyword[p->random];
        }
        return newhead.next;
    }
};