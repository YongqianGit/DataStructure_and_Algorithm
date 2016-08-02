 vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int> > res;
        if (sz < 3) return res;
        sort(nums.begin(), nums.end() );
        for (int i = 0; i < sz; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) {continue;}
            
            int l = i + 1, r = sz - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    int a [] = {nums[i], nums[l], nums[r]};
                    res.push_back(vector<int> (a, a + 3) );
                    l++; r--; 
                    while (nums[l] == nums[l - 1]) {l++;}
                    while (nums[r] == nums[r + 1]) {r--;}
                }
                else if (sum < 0) {
                    l++;
                }
                else { // sum > 0
                    r--;
                }
            }
        }
        
        return res;
    }
