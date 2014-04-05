/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return ;
        TreeLinkNode *head = NULL, *tail = NULL, *p = root;
        for (; p; p = p->next) {
            insertLink(head, tail, p->left);
            insertLink(head, tail, p->right);
        }
        connect(head);
    }
private:
    void insertLink(TreeLinkNode * &head, TreeLinkNode * &tail, TreeLinkNode * node) {
        if (node != NULL) {
            if (head == NULL) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }
    }
};
