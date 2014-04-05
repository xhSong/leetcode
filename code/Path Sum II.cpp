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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        getPathSum(root, sum, path, ans);
        return ans;
    }
private:
    void getPathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &ans) {
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return ;
        }
        path.push_back(root->val);
        getPathSum(root->left, sum - root->val, path, ans);
        getPathSum(root->right, sum - root->val, path, ans);
        path.pop_back();
    }
};
