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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return _isSymmetric(root->left, root->right);
    }
private:
    bool _isSymmetric(TreeNode *root1, TreeNode *root2) {
        if (root1 == NULL || root2 == NULL) {
            return root1 == root2;
        }
        if (root1->val != root2->val) return false;
        return _isSymmetric(root1->left, root2->right) && _isSymmetric(root1->right, root2->left);
    }
};