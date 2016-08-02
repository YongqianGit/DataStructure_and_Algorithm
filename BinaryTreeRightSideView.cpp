void gen_right(TreeNode *root, int lev, vector<int>& res) {
        if (!root) {return;} 
        
        if (res.size() < lev) {res.push_back(root->val);}
        
        gen_right(root->right, lev + 1, res);
        gen_right(root->left, lev + 1, res);
    }

vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {return res;}
        
        res.push_back(root->val);
        int lev = 1;
        
        gen_right(root, lev, res);
        
        return res;
    }


// Non-recursive, preorder
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> res;
        if (!root) {return res;}
        
        stack<int> level;
        stack<TreeNode*> nd;
        
        res.push_back(root->val);
        nd.push(root);
        level.push(1);
        
        while (!nd.empty() ) {
            TreeNode *cur = nd.top(); nd.pop();
            int lev = level.top(); level.pop();
            
            if (res.size() < lev) {res.push_back(cur->val); }
            
            if (cur->left) {
                nd.push(cur->left);
                level.push(lev + 1);
            }
            
            if (cur->right) {
                nd.push(cur->right);
                level.push(lev + 1);
            }
            
        }
        
        return res;
        
    }
