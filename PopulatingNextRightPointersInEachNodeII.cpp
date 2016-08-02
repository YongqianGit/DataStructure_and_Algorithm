void connect(TreeLinkNode *root) {
        if (!root) return;
        
        if (root->left && root->right) {
            root->left->next = root->right;
        }
        
        if (root->next) {
            TreeLinkNode *next_left = root->right? root->right : root->left;
            if (next_left) {
                
                TreeLinkNode *next_right = NULL;

                for (auto it = root->next; it; it = it->next) {
                    next_right = it->left? it->left : it->right;
                    if (next_right) {break;}
                }
                
                next_left->next = next_right;
                
            }
            
        }
        
        connect(root->right);
        connect(root->left);
    }
