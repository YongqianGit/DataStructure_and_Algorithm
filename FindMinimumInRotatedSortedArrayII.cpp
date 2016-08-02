int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] < nums[r]) { // right sorted
                if (m == 0 || nums[m-1] > nums[m]) {return nums[m];}
                r = m - 1;
            }
            else if (nums[m] > nums[r]) { // left sorted
                l = m + 1;
            }
            else { // ==
                r--;
            }
        }
        
        return nums[l];
    }
