void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 1) {return;}
        
        int sel = -1;
        for (int i = sz - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                sel = i - 1;
                break;
            }
        }
        
        if (sel == -1) {
            reverse(nums.begin(), nums.end() );
            return;
        }
        
        reverse(nums.begin() + sel + 1, nums.end() );
        auto it = upper_bound(nums.begin() + sel + 1, nums.end(), nums[sel] );
        swap(*it, nums[sel]);
        
    }
