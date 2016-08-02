    // assume no duplicate exists in the array.
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        int l = 0, r = sz - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) { // right sorted
                if (m == 0 || nums[m - 1] > nums[m]) {
                    return nums[m];
                }
                else {
                    r = m - 1;
                }
            }
            else { // nums[m] > nums[r], left sorted
                l = m + 1;
            }
            
            // l == r will ternimate, so there is NO nums[m] == nums[r]!!
        }
        
        return nums[l];
    }
