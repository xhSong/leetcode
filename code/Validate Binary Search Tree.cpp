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
    bool isValidBST(TreeNode *root) {
        int rmax, rmin;
        return isValidBST(root, rmax, rmin);
    }
private:
    bool isValidBST(TreeNode *root, int &rmax, int &rmin) {
        if (root == NULL) return true;
        rmax = rmin = root->val;
        if (root->left) {
            int cmax, cmin;
            if (isValidBST(root->left, cmax, cmin) == false || cmax >= root->val) {
                return false;
            }
            rmax = max(rmax, cmax), rmin = min(rmin, cmin);
        }
        if (root->right) {
            int cmax, cmin;
            if (isValidBST(root->right, cmax, cmin) == false || cmin <= root->val) {
                return false;
            }
            rmax = max(rmax, cmax), rmin = min(rmin, cmin);
        }
        return true;
    }
};