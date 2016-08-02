vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int sz = nums.size();
        if (sz < 1) return res;
        
        res.push_back(nums);
        
        for (int i = 0; i < sz - 1; i++) { // position !!!
            int sz_res = res.size();
            for (int j = 0; j < sz_res; j++) {
                
                int pos = i + 1; // swap nums[i] with nums[i+1:end] respectively!!
                while (pos < sz) {
                    vector<int> sol = res[j];
                    swap(sol[i], sol[pos]);
                    res.push_back(sol);
                    pos++;
                }
            }
            
        }
        
        return res;
    }
