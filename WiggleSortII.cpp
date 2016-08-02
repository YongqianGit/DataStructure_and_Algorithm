void wiggleSort(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2) return;
        
        vector<int> res(sz, 0);
        sort(nums.begin(), nums.end() );
        int m = (sz + 1) / 2 - 1;
        for (int i = 0; i < sz / 2; i++) {
            res[2*i + 1] = nums[sz - 1 - i];
            res[2*i] = nums[m - i];
        }
        
        if (sz % 2 != 0) { // odd length
            res.back() = nums[0];
        }
        
        nums = res;
    }
