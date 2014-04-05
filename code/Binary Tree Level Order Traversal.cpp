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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        vector<int> nowval;
        vector<TreeNode *> up, now;
        now.push_back(root);
        while (now.size()){
            nowval.clear();
            for (int i = 0; i < now.size(); ++i) {
                nowval.push_back(now[i]->val);
            }
            ans.push_back(nowval);
            up = now;
            now.clear();
            for (int i = 0; i < up.size(); ++i) {
                if (up[i]->left) {
                    now.push_back(up[i]->left);
                }
                if (up[i]->right) {
                    now.push_back(up[i]->right);
                }
            }
        }
        return ans;
    }
};