vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) {return vector<vector<int> > ();}
        
        vector<pair<TreeNode*, int> > stat;
        int lev = 0, cnt = 0;
        stat.push_back( make_pair(root, lev) );
         
        while (cnt < stat.size() ) {
            lev = stat[cnt].second;
            root = stat[cnt].first;
  
            if (root->left) { stat.push_back(make_pair(root->left, lev + 1) ); }
            if (root->right) { stat.push_back(make_pair(root->right, lev + 1) ); }
            
            cnt++;
        }
        
        vector<vector<int> > res (lev + 1, vector<int> () );
        
        for (auto item : stat) {
            res[ lev - item.second ].push_back(item.first->val);
        }
        
        return res;
    }
