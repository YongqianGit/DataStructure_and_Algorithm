int is_balance(TreeNode *root, bool &balance) {
        if (balance) {
            if (!root) return 0;
            
            int l = is_balance(root->left, balance) + 1;
            int r = is_balance(root->right, balance) + 1;
            
            if ( abs(l - r) > 1 ) {balance = false;} 
            return max(l, r);
        }
        else {return INT_MIN;}
    }

bool isBalanced(TreeNode* root) {
        bool balance = true;
        is_balance(root, balance);
        return balance;
    }
