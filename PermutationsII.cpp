vector<vector<int>> permuteUnique0(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back(nums);
        int sz = nums.size();
        int pos = 0; // swap nums[pos] with nums[pos+1:end]
        while ( pos < sz - 1 ) {
            int sz_res = res.size();
            for (int i = 0; i < sz_res; i++) {
                sort(res[i].begin() + pos, res[i].end() );
                
                // do it for each res[i] vector!!
                for (int j = pos + 1; j < sz; j++) {
                    if (res[i][j] == res[i][j-1]) continue;
                    vector<int> sol = res[i];
                    swap(sol[pos], sol[j]);
                    res.push_back(sol);
                }
            }
            pos++;
        }
        
        
        return res;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back(nums);
        int sz = nums.size();
        
        for (int i = 0; i < sz - 1; i++) { // positions!!!
            int sz_res = res.size();
            
            for (int k = 0; k < sz_res; k++) {
                
                sort(res[k].begin() + i, res[k].end() );
                int pos = i + 1; //  each vector in res switches i with [i+1:end]
                
                while (pos < sz) {
                    if (res[k][pos] == res[k][pos-1]) {pos++; continue;}// Do NOT forget pos++ !!!
                    vector<int> sol = res[k];
                    swap(sol[i], sol[pos]);
                    res.push_back(sol);
                    pos++;
                }
                
            }
        }
        
        return res;
    }
