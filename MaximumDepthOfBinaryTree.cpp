int maxDepth(TreeNode* root) {
        if (!root) {return 0;}
        
        int l = maxDepth(root->left) + 1;
        int r = maxDepth(root->right) + 1;
        
        return max(l, r);
    }
