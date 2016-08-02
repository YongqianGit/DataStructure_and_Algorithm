void search_path(TreeNode *root, int sum, vector<int>& sol, vector<vector<int> >& res) {
        
        if (!root) {return;}
        
        if (!root->left && !root->right) {
            if (sum == root->val) {
                sol.push_back(root->val);
                res.push_back(sol);
                sol.pop_back();
            }
            return;
        }
        
        if (root->left) {
            sol.push_back(root->val);
            search_path(root->left, sum - root->val, sol, res);
            sol.pop_back();
        }
        
        if (root->right) {
            sol.push_back(root->val);
            search_path(root->right, sum - root->val, sol, res);
            sol.pop_back();
        }
        
        
    }

vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if (!root) return res;
        vector<int> sol;
        search_path(root, sum, sol, res);
        return res;
    }
