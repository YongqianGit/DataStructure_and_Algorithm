bool compare(TreeNode *l, TreeNode *r) {
        if (!l || !r) {
            if (l || r) return false;
            else return true;
        }
        
        if (l->val != r->val ) return false;
        if ( !compare(l->left, r->right) ) return false;
        if ( !compare(l->right, r->left) ) return false;
        
        return true;
    }

bool isSymmetric(TreeNode* root) {
        if (!root) {return true;}
        
        return compare(root->left, root->right);
    }
