// Preorder. Perfect binary tree
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        if (root->left && root->right) {
            root->left->next = root->right;
        }
        
        if (root->next) {
            if (root->right) root->right->next = root->next->left;
            // If last layer, then NO root->right!!! Careful!!!
        }
        
        connect(root->left);
        connect(root->right);
    }
