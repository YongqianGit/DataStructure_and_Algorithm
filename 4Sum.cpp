 void gen_comb(vector<int>& nums, int target, int k, int start, \
    vector<int>& sol, vector<vector<int> >& res) {
        if (k == 2) {
            int l = start, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    sol.push_back(nums[l]);
                    sol.push_back(nums[r]);
                    res.push_back(sol);
                    sol.pop_back(); sol.pop_back();
                    
                    l++; r--;
                    
                    while ( l <= r && nums[l-1] == nums[l] ) {l++;}
                    while ( r >= l && nums[r+1] == nums[r] ) {r--;}
                    
                    
                }
                else if (target > sum) {
                    l++;
                }
                else {r--;}
                
            }
            
            return;
        } 
        
        for (int i = start; i <= nums.size() - k ; i++) {
            if (i > start && nums[i] == nums[i-1]) {continue;}
            
            sol.push_back(nums[i]);
            gen_comb(nums, target - nums[i], k - 1, i + 1, sol, res);
            sol.pop_back();
        }
    }

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int> > res;
        
        if (nums.size() < 4) { return res;}
        
        vector<int> sol;
        
        sort(nums.begin(), nums.end() );
        gen_comb(nums, target, 4, 0, sol, res);
        
        return res;
    }
