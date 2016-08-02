void search (TreeNode *root, int &k, int &res, bool &found) {
        if (!root) {return;}
        
        if (!found) {
            if (root->left) search(root->left, k, res, found);
            
            if (k-- == 1) {
                res = root->val;
                found = true;
                return;
            }
            
            if (root->right) search(root->right, k, res, found);
        }
        
    }


int kthSmallest0(TreeNode* root, int k) {
        bool found = false;
        int res = 0;
        search (root, k, res, found);
        return res;
    }
    
    
    // Non-recursive, inorder
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> node;
        while (root || !node.empty() ) {
            if (root) {
                node.push(root);
                root = root->left;
            }
            else {
                root = node.top();
                node.pop();
                if (k-- == 1) {return root->val;}
                root = root->right;
            }
        }
        
        return -1;
        
    }
