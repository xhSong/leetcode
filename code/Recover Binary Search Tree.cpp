/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        pre = first = first_next = second = nullptr;
        DFS(root);
        if (first && second) {
            swap(first->val, second->val);
        } else {
            swap(first->val, first_next->val);
        }
    }
private:
    void DFS(TreeNode* root) {
        if (root) {
            DFS(root->left);
            if (pre && pre->val > root->val) {
                if (first) second = root;
                else {
                    first = pre;
                    first_next = root;
                }
            }
            pre = root;
            DFS(root->right);
        }
    }
    TreeNode *first, *second, *pre, *first_next;
};