pair<int, int> rob_recurse(TreeNode *root) {
        if (!root) {return {0, 0}; }
        
        pair<int, int> tr_l = rob_recurse(root->left);
        pair<int, int> tr_r = rob_recurse(root->right);
        // <current max, last layer's max>
        
        pair<int, int> cur;
        cur.second = tr_l.first + tr_r.first;
         
        cur.first = max(cur.second, root->val + tr_l.second + tr_r.second );
        
        return cur;
        
    }

int rob(TreeNode* root) {
        
        // if (!root) {return 0;}
        
        return rob_recurse(root).first;
    }
