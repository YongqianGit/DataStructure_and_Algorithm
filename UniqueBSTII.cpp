vector<TreeNode*> gen_BST(int l, int r) {
        
        if (l > r) {return {NULL};}
        
        vector<TreeNode*> res;
        

        for (int cnt = l; cnt <= r; cnt++) {
            vector<TreeNode*> tr_l = gen_BST(l, cnt - 1);
            vector<TreeNode*> tr_r = gen_BST(cnt + 1, r);
            
            for (int i = 0; i < tr_l.size(); i++) {
                for (int j = 0; j < tr_r.size(); j++) {
                    TreeNode *root = new TreeNode (cnt);
                    root->left = tr_l[i];
                    root->right = tr_r[j];
                    res.push_back(root);
                }
            }
            
        }
        
        return res;
    }
