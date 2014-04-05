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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> nodes;
        postorderTraversal(root, nodes);
        return nodes;
    }
private:
    void postorderTraversal(TreeNode *root, vector<int> &nodes) {
        if (root == NULL) return;
        postorderTraversal(root->left, nodes);
        postorderTraversal(root->right, nodes);
        nodes.push_back(root->val);
    }
};