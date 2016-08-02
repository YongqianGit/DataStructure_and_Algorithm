 void recover(TreeNode *root, TreeNode* &p1, TreeNode* &p2, TreeNode* &prev) {
        if (!root ) {return;}
        
        recover(root->left, p1, p2, prev);
        
        if (prev && prev->val > root->val) {
            if (!p1) {
                p1 = prev;
            } 
            p2 = root;
        } 
        prev = root;
        
        recover(root->right, p1, p2, prev);
        
    }

void recoverTree(TreeNode* root) {
        TreeNode *p1 = NULL, *p2 = NULL, *prev = NULL;
        recover(root, p1, p2, prev);
        swap(p1->val, p2->val);
    }
