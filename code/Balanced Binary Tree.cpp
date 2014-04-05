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
    bool isBalanced(TreeNode *root) {
        int depth;
        return _isBalanced(root, depth);
    }
private:
    bool _isBalanced(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int leftdepth, rightdepth;
        if (_isBalanced(root->left, leftdepth) && _isBalanced(root->right, rightdepth)) {
            depth = max(leftdepth, rightdepth) + 1;
            return abs(leftdepth - rightdepth) <= 1;
        }
        return false;
    }
};