void sum_iterate(TreeNode *root, int &sum) {
        if (!root ) return;
        
        if (!root->left && !root->right) {
            sum += root->val;
            return;
        }
        
        if (root->left) {
            root->left->val += root->val * 10;
            sum_iterate(root->left, sum);
        }
        
        if (root->right) {
            root->right->val += root->val * 10;
            sum_iterate(root->right, sum);
        }
    }

int sumNumbers(TreeNode* root) {
        if (!root) {return 0;}
        
        int sum = 0;
        
        sum_iterate(root, sum);
        
        return sum;
        
    }
