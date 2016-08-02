vector<int> postorderTraversal0(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    
    // Non-recurse
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> node;
        vector<int> res;
        TreeNode *last = NULL;
        while (root || !node.empty() ) {
            if (root) {
                node.push(root);
                root = root->left;
            }
            else {
                TreeNode *cur = node.top();
                if (cur->right && cur->right != last) {
                    
                    root = cur->right;
                }
                else {
                    node.pop();
                    res.push_back(cur->val);
                    last = cur;
                }
            }
        }
        
        return res;
    }

void postorder(TreeNode *root, vector<int>& res) {
        if (root) {
            postorder(root->left, res);
            postorder(root->right, res);
            res.push_back(root->val);
        }
    }
