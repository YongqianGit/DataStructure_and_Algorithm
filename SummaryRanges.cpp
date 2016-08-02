string gen_range(vector<int>& nums, int l, int r) {
        if (l == r) {
            return to_string(nums[l]);
        }
        else {
            return to_string(nums[l]) + "->" + to_string(nums[r]);
        }
    }

vector<string> summaryRanges(vector<int>& nums) {
        int sz = nums.size(), l = 0;
        
        vector<string> res;
        if (sz < 1) return res;
        
        
        for (int i = 1; i < sz; i++) {
            if (nums[i] == nums[i-1] + 1) {
                continue;
            }
            else {
                res.push_back( gen_range(nums, l, i - 1) );
                l = i;
            }
        }
        
        res.push_back( gen_range(nums, l, sz - 1) );
        
        return res;
    }
