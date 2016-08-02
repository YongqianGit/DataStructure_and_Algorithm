int findPeakElement(vector<int>& nums) {
        int sz = nums.size(), l = 0, r = sz - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if ( (m == 0 || nums[m - 1] < nums[m]) && \
            (m == sz - 1 || nums[m] > nums[m + 1]) ) {
                return m;
            }
            
            if (m > 0 && nums[m - 1] > nums[m]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return l;
    }
