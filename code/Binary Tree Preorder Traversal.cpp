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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> nodes;
        preorderTraversal(root, nodes);
        return nodes;
    }
private:
    void preorderTraversal(TreeNode *root, vector<int> &nodes) {
        if (root == NULL) return;
        nodes.push_back(root->val);
        preorderTraversal(root->left, nodes);
        preorderTraversal(root->right, nodes);
    }
};