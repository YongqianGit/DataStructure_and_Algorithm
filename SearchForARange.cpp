int search_left(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r ) {
            int m = l + (r - l) / 2;
            
            if (target > nums[m]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return l;
    }
    
int search_right(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r ) {
            int m = l + (r - l) / 2;
            
            if (target < nums[m]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return r;
    }

vector<int> searchRange(vector<int>& nums, int target) {
        
        int res_l = search_left(nums, target);
        int res_r = search_right(nums, target);
        
        vector<int> res(2, -1);
        if (res_l >= 0 && nums[res_l] == target) {
            res[0] = res_l;
            res[1] = res_r;
        }
        
        return res;
    }
