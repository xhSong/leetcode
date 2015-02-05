class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            path.push_back(root);
            root = root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return path.size() != 0;
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *ptr = path[path.size() - 1];
        int value = ptr->val;
        if (ptr->right) {
            ptr = ptr->right;
            path.push_back(ptr);
            while (ptr->left) {
                ptr = ptr->left;
                path.push_back(ptr);
            }
        } else {
            while (path.size() >= 2 && path[path.size() - 2]->right == path[path.size() - 1]) {
                path.pop_back();
            }
            path.pop_back();
        }
        return value;
    }
private:
    vector<TreeNode*> path;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
