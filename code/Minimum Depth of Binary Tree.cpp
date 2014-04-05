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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int ans = LONG_MAX;
        if (root->left) {
            ans = min(ans, minDepth(root->left) + 1);
        }
        if (root->right) {
            ans = min(ans, minDepth(root->right) + 1);
        }
        return ans;
    }
};