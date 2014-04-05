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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0) return NULL;
        int n = inorder.size();
        int post[n], in[n];
        for (int i = 0; i < n; ++i) {
            post[i] = postorder[i];
            in[i] = inorder[i];
        }
        return _bulidTree(post, in, n);
    }
private:
    TreeNode *_bulidTree(int post[], int in[], int n) {
        if (n == 0) return NULL;
        if (n == 1) {
            return new TreeNode(post[n - 1]);
        }
        int k = 0;
        while(k < n && in[k] != post[n - 1]) ++ k;
        TreeNode *root = new TreeNode(post[n - 1]);
        root->left = _bulidTree(post, in, k);
        root->right = _bulidTree(post + k, in + 1 + k, n - k - 1);
        return root;
    }
};