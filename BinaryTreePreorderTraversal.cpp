vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> stat;
        stat.push(root);
        vector<int> res;
        
        while (!stat.empty() ) {
            root = stat.top();
            stat.pop();
            res.push_back(root->val);
            
            if (root->right) {
                stat.push(root->right);
            }
            
            if (root->left) {
                stat.push(root->left);
            }
        }
        
        return res;
    }
