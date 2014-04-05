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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) return NULL;
        int n = preorder.size();
        int pre[n], in[n];
        for (int i = 0; i < n; ++i) {
            pre[i] = preorder[i];
            in[i] = inorder[i];
        }
        return _bulidTree(pre, in, n);
    }
private:
    TreeNode *_bulidTree(int pre[], int in[], int n) {
        if (n == 0) return NULL;
        if (n == 1) {
            return new TreeNode(pre[0]);
        }
        int k = 0;
        while(k < n && in[k] != pre[0]) ++ k;
        TreeNode *root = new TreeNode(pre[0]);
        root->left = _bulidTree(pre + 1, in, k);
        root->right = _bulidTree(pre + 1 + k, in + 1 + k, n - k - 1);
        return root;
    }
};