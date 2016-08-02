// Preorder
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> node;
        node.push(root);
        vector<TreeNode*> res;
        
        while (!node.empty() ) {
            root = node.top();
            node.pop();
            res.push_back(root);
            
            if (root->right) node.push(root->right);
            
            if (root->left) node.push(root->left);
        } 
        
        for (int i = 0; i < res.size() - 1; i++) {
            res[i]->left = NULL;
            res[i]->right = res[i+1];
        }
        
        
    }
