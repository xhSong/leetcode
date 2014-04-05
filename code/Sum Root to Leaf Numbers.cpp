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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        _sumNumbers(root, 0, sum);
        return sum;
    }
private:
    void _sumNumbers(TreeNode *root, int number, int &sum) {
        if (root == NULL) return;
        number = number * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += number;
        }
        _sumNumbers(root->left , number, sum);
        _sumNumbers(root->right, number, sum);
    }
};