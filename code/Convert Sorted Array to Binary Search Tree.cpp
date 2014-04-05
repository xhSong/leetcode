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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int a[num.size()], n = num.size();
        for (int i = 0; i < n; ++i) {
            a[i] = num[i];
        }
        return _gen(a, n);
    }
private:
    TreeNode *_gen(int a[], int n) {
        if (n == 0) return NULL;
        TreeNode *root = new TreeNode(a[n / 2]);
        root->left = _gen(a, n / 2);
        root->right = _gen(a + n / 2 + 1, n - n / 2 - 1);
        return root;
    }
};