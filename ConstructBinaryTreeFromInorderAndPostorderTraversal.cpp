TreeNode* gen_tree(vector<int>& inorder, int s_i, int e_i, \
    vector<int>& postorder, int s_p, int e_p) {
        
        if (s_i > e_i) {return NULL;}
        
        TreeNode *root = new TreeNode (postorder[e_p]);
        
        int in_id = 0;
        for (int i = s_i; i <= e_i; i++) {
            if (inorder[i] == root->val) {
                in_id = i;
                break;
            }
        }
        
        int len_l = in_id - s_i;
        int len_r = e_i - in_id;
        
        TreeNode *tr_l = gen_tree(inorder, s_i, in_id - 1, postorder, s_p, s_p + len_l - 1);
        
        TreeNode *tr_r = gen_tree(inorder, in_id + 1, e_i, postorder, e_p - len_r, e_p - 1);
        
        root->left = tr_l;
        root->right = tr_r;
        
        return root;
        
    }

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return gen_tree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
