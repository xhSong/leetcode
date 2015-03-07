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
        DFS(root, nullptr);
    }
private:
    void DFS(TreeLinkNode *node, TreeLinkNode *next) {
        if (node) {
            node->next = next;
            if (!node->left && !node->right) return ;
            for (; next && !next->left && !next->right; next = next->next);
            if (next) next = next->left? next->left: next->right;
            DFS(node->right, next);
            DFS(node->left, node->right? node->right: next);
        }
    }
};