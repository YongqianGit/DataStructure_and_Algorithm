bool canJump(vector<int>& nums) {
        
        int cur_max = 0;
        int sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            cur_max = max(cur_max - 1, nums[i]);
            if (cur_max <= 0) return false;
        }
        
        return true;
    }


 bool canJump2(vector<int>& nums) {
        int sz = nums.size();
        int cur_max = 0;
        for (int i = 0; i < sz; i++) {
            if (cur_max >= sz - 1 || cur_max < i) {
                break;
            }
            cur_max = max(cur_max, nums[i] + i);
        }
        
        return cur_max >= sz - 1 ;
    }
