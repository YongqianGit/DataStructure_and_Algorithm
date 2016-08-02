void gen_sub(vector<int>& nums, int start, \
    vector<int>& sol, vector<vector<int> >& res) {
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i-1] == nums[i]) {continue;}
            
            sol.push_back(nums[i]);
            res.push_back(sol);
            gen_sub(nums, i + 1, sol, res);
            sol.pop_back();
        }
    }

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> sol;
        res.push_back(sol);
        sort(nums.begin(), nums.end() );
        gen_sub(nums, 0, sol, res);
        return res;
    }
