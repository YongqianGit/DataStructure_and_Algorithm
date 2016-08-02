/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    queue<int> nd;
    void inorder_recurse(TreeNode *root) {
        if (root) {
            inorder_recurse(root->left);
            nd.push(root->val);
            inorder_recurse(root->right);
        }
    }
    
    // Non-recursive
    void inorder(TreeNode *root) {
        stack<TreeNode*> all_nd;
        while ( !all_nd.empty() || root ) {
            if (root) {
                all_nd.push(root);
                root = root->left;
            }
            else {
                root = all_nd.top();
                all_nd.pop();
                nd.push(root->val);
                
                root = root->right;

            }
        }
    }
public:
    BSTIterator(TreeNode *root) {
        inorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nd.empty();
    }

    /** @return the next smallest number */
    int next() {
        int cur = nd.front();
        nd.pop();
        return cur;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
