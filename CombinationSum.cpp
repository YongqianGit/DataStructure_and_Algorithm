void gen_comb(vector<int>& can, int start, int target, \
    vector<int>& sol, vector<vector<int> >& res) {
        if (target < 0 ) {return;}
        
        if (target == 0) {
            res.push_back(sol);
            return;
        }
        
        for (int i = start; i < can.size(); i++) {
            sol.push_back(can[i]);
            gen_comb(can, i, target - can[i], sol, res);
            sol.pop_back( );
        }
    }

// The same repeated number may be chosen from C unlimited number of times. 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> sol;
        
        gen_comb(candidates, 0, target, sol, res);
        return res;
    }
