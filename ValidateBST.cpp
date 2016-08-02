void inorder(TreeNode *root, vector<int>& res) {
        if (root) {
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }
    }

bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        for (int i = 1; i < res.size(); i++) {
            if (res[i-1] >= res[i]) {return false;}
        }
        
        return true;
    }
