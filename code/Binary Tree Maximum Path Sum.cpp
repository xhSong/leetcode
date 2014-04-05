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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int ans = root->val;
        maxPath(root, ans);
        return ans;
    }
private:
    int maxPath(TreeNode *root, int &ans) {
        if (root == NULL) return 0;
        int leftPath = max(maxPath(root->left, ans), 0);
        int rightPath = max(maxPath(root->right, ans), 0);
        ans = max(leftPath + rightPath + root->val, ans);
        return max(leftPath, rightPath) + root->val;
    }
};