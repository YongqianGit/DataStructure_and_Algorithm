int qsort(vector<int>& nums, int l, int r) {
        
        int& pivot = nums[l++];
        while (l <= r) {
            while (nums[l] >= pivot && l <= r ) {l++;}
            while (nums[r] <= pivot && r >= l) {r--;}
            if (l > r) {break;}
            swap(nums[l], nums[r]);
        }
        
        swap(pivot, nums[r]);
        return r;
    }
    

int findKthLargest(vector<int>& nums, int k) {
        k--;
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int rank = qsort(nums, l, r);
            if (rank == k) {break;}
            else if (rank < k) {
                l = rank + 1;
            }
            else { // rank > k
                r = rank - 1;
            }
        }
        
        return nums[k];
    }
    
