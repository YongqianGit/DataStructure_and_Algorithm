int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2) {return sz;}
        
        int pos = 1;
        
        for (int i = 1; i < sz; i++) {
            if (nums[i] != nums[i-1]) {
                nums[pos++] = nums[i];
            }
        }
        
        return pos;
    } 
