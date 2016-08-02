bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        
        if (root->left && hasPathSum(root->left, sum - root->val)) {return true;}
        
        if (root->right && hasPathSum(root->right, sum - root->val)) {return true;}
        
        if (!root->left && !root->right) {
            return sum == root->val;
        }
        
        return false;
    }
