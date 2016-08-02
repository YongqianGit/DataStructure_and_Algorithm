void gen_comb(vector<int>& can, int target, int start, \
    vector<int>& sol, vector<vector<int> >& res) {
        if (target < 0) {return;}
        if (target == 0) {
            res.push_back(sol);
            return;
        }
        
        for (int i = start; i < can.size(); i++) {
            if (i > start && can[i-1] == can[i]) {continue;}
            sol.push_back(can[i]);
            gen_comb(can, target - can[i], i + 1, sol, res);
            sol.pop_back();
        }
    }

 // Each number in C may only be used once in the combination. 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> sol;
        if (candidates.empty() ) return res;
        sort(candidates.begin(), candidates.end() );
        gen_comb(candidates, target, 0, sol, res);
        return res;
    }
