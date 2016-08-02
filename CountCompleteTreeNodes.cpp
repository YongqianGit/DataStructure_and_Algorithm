int is_full(TreeNode *root) {
        
        if (!root) return 0;
        
        int cnt = 1;
        
        TreeNode *l = root, *r = root; // start from the toppest root!
        
        while (l && r) {
            cnt *= 2;
            l = l->left;
            r = r->right;
        }
        
        if (l || r) {return -1;} // NOT full binary tree
        
        return cnt - 1;
    }

int countNodes(TreeNode* root) {
        int cnt = is_full(root);
        
        if (cnt  == -1) {
            int cnt_l = countNodes(root->left);
            int cnt_r = countNodes(root->right);
            return cnt_l + cnt_r + 1;
        }
        else {
            return cnt;
        }
    }
