void gen_path(TreeNode* root, string sol, vector<string>& res) {
        if (!root) {return;}
        
        sol += to_string(root->val);
        
        if (!root->left && !root->right) {
            res.push_back(sol);
            return;
        }

        if (root->left) gen_path(root->left, sol + "->", res);
        if (root->right) gen_path(root->right, sol + "->", res);
        
    }


vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;

        gen_path(root, "", res);
        return res;
    }
