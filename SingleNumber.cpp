int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int item : nums) {
            res ^= item;
        }
        
        return res;
    }
