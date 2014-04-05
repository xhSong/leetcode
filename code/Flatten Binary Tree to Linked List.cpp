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
    void flatten(TreeNode *root) {
        TreeNode *begin, *end;
        _flatten(root, begin, end);
    }
private:
    void _flatten(TreeNode *root, TreeNode * &begin, TreeNode * &end) {
        if (root == NULL) {
            begin = end = NULL;
            return;
        }
        TreeNode *lbegin, *lend, *rbegin, *rend;
        _flatten(root->left, lbegin, lend);
        _flatten(root->right, rbegin, rend);
        root->left = NULL;
        begin = end = root;
        if (lbegin) {
            end->right = lbegin;
            end = lend;
        }
        if (rbegin) {
            end->right = rbegin;
            end = rend;
        }
    }
};
