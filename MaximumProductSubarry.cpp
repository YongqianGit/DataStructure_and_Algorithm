int maxProduct(vector<int>& nums) {
        if (nums.empty() ) return 0;
        int cur_max = nums[0], cur_min = nums[0], all_max = nums[0];
        int sz = nums.size();
        for (int i = 1; i < sz; i++) {
            int cur_tmp = cur_max;
            cur_max = max(nums[i], max(cur_max * nums[i], cur_min * nums[i]) );
            cur_min = min(nums[i], min(cur_tmp * nums[i], cur_min * nums[i]) );
            
            all_max = max(cur_max, all_max);
        }
        
        return all_max;
    }
