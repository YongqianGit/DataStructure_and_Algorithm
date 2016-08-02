TreeNode* gen_BST (vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        
        int m = l + (r - l) / 2;
        
        TreeNode* root = new TreeNode (nums[m]);
        
        TreeNode* tr_l = gen_BST(nums, l, m - 1);
        TreeNode* tr_r = gen_BST(nums, m + 1, r);
        
        root->left = tr_l;
        root->right = tr_r;
        
        return root;
    }

TreeNode* sortedArrayToBST(vector<int>& nums) {
        return gen_BST(nums, 0, nums.size() - 1);
    }
