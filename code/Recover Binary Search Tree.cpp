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
    void recoverTree(TreeNode *root) {
        if (root == NULL) return ;
        TreeNode *mistakeroot, *minp, *maxp, *lminp, *lmaxp, *rminp, *rmaxp;
        mistakeroot = _mistake(root, minp, maxp);
        
        _mistake(mistakeroot->left, lminp, lmaxp);
        _mistake(mistakeroot->right, rminp, rmaxp);
        
        if ((lmaxp && lmaxp->val > mistakeroot->val) && (rminp && rminp->val < mistakeroot->val)) {
            _swap(lmaxp, rminp);
            return ;
        }
        if (lmaxp && lmaxp->val > mistakeroot->val) {
            _swap(lmaxp, mistakeroot);
        }
        if (rminp && rminp->val < mistakeroot->val) {
            _swap(rminp, mistakeroot);
        }
    }
private:
    void _swap(TreeNode *p, TreeNode *q) {
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
    }
    
    TreeNode* _mistake(TreeNode *root, TreeNode *&minp, TreeNode *&maxp) {
        if (root == NULL) {
            minp = maxp = NULL;
            return NULL;
        }
    
        TreeNode *lminp, *rminp, *lmaxp, *rmaxp, *lmistake, *rmistake;
        
        lmistake = _mistake(root->left, lminp, lmaxp);
        rmistake = _mistake(root->right, rminp, rmaxp);
        
        minp = maxp = root;
        if (lminp && lminp->val < minp->val) minp = lminp;
        if (rminp && rminp->val < minp->val) minp = rminp;
        if (lmaxp && lmaxp->val > maxp->val) maxp = lmaxp;
        if (rmaxp && rmaxp->val > maxp->val) maxp = rmaxp;
        
        
        if ((lmaxp && lmaxp->val > root->val) || (rminp && rminp->val < root->val)) return root;
        if (lmistake) return lmistake;
        if (rmistake) return rmistake;
        return NULL;
    }
};