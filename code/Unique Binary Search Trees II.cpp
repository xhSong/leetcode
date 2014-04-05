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
    vector<TreeNode *> generateTrees(int n) {
        return _gen(1, n);
    }
private:
    vector<TreeNode *> _gen(int left, int right) {
        vector<TreeNode *> roots;
        if (left > right)  {
            roots.push_back(NULL);
            return roots;
        }
        for (int k = left; k <= right; ++k) {
            vector<TreeNode *> lefttree = _gen(left, k - 1);
            vector<TreeNode *> righttree = _gen(k + 1, right);
            for (int i = 0; i < lefttree.size(); ++i) {
                for (int j = 0; j < righttree.size(); ++j) {
                    TreeNode *root = new TreeNode(k);
                    root->left = lefttree[i];
                    root->right = righttree[j];
                    roots.push_back(root);
                }
            }
        }
        return roots;
    }
};