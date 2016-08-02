bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            if (target == nums[m]) return true;
            
            if (nums[m] < nums[r]) { // right sorted
                if (target > nums[m] && target <= nums[r]) { // target on right
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else if (nums[m] > nums[r]) { // left sorted
                if (target < nums[m] && target >= nums[l]) { // target on left
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else { // nums[m] == nums[r]
                r--;
            }
        }
        
        return nums[l] == target;
    }
