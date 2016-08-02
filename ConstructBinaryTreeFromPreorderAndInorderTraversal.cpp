TreeNode* gen_pre_in(vector<int>& preorder, int s_p, int e_p, \
    vector<int>& inorder, int s_i, int e_i) {
        if (s_p > e_p) {return NULL;}
        
        TreeNode *root = new TreeNode (preorder[s_p]);
        
        int id_in = 0;
        
        for (int i = s_i; i <= e_i; i++) {
            if (inorder[i] == root->val) {
                id_in = i;
                break;
            }
        }
        
        int len_l = id_in - s_i;
        int len_r = e_i - id_in;
        
        TreeNode *tr_l = gen_pre_in(preorder, s_p + 1, s_p + len_l, inorder, s_i, id_in - 1);
        TreeNode *tr_r = gen_pre_in(preorder, e_p - len_r + 1, e_p, inorder, id_in + 1, e_i);
        
        root->left = tr_l;
        root->right = tr_r;
        
        return root;
    }


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size() ) return NULL;
        
        return gen_pre_in(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1 ); 
    }
    
