vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back(vector<int> () );
        int sz = nums.size();
        if (sz < 1) {return res;}
        
        for (int item : nums) {
            int sz_res = res.size();
            for ( int i = 0; i < sz_res; i++ ) {
                vector<int> sol = res[i];
                sol.push_back(item);
                res.push_back(sol);
            }
        }
        
        return res;
    }
