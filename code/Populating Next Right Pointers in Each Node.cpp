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
        queue<TreeLinkNode *> nodes;
        queue<int> depths;
        nodes.push(root); depths.push(0);
        while (nodes.size()) {
            root = nodes.front();
            int d = depths.front();
            nodes.pop(); depths.pop();
            if (nodes.size() && depths.front() == d) root->next = nodes.front();
            else root->next = NULL;
            if (root->left) {
                nodes.push(root->left); depths.push(d + 1);
            }
            if (root->right) {
                nodes.push(root->right); depths.push(d + 1);
            }
        }
    }
};