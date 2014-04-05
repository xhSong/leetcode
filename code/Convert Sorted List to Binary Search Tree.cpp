/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> vals;
        for (ListNode *p = head; p; p = p->next) {
            vals.push_back(p->val);
        }
        return _gen(vals, 0, vals.size());
    }
private:
    TreeNode *_gen(vector<int> &vals, int left, int right) {
        if (left >= right) {
            return NULL;
        }
        int mid = (left + right) >> 1;
        TreeNode *root = new TreeNode(vals[mid]);
        root->left = _gen(vals, left, mid);
        root->right = _gen(vals, mid + 1, right);
        return root;
    }
};