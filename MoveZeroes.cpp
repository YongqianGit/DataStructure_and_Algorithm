void moveZeroes(vector<int>& nums) {
        int sz = nums.size(), pos = 0;
        
        for (int i = 0; i < sz; i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }
        
        while (pos < sz) {
            nums[pos++] = 0;
        }
    }
