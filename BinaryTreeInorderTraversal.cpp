vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> node;
        vector<int> res;
        
        while (root || !node.empty() ) {
            if (root) {
                node.push(root);
                root = root->left;
            }
            else {
                root = node.top();
                node.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        
        return res;
    }
