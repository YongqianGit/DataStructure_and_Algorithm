bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz = nums.size(), back = 0;
        set<int> window;
        
        for (int i = 0; i < sz; i++) {
            
            if (window.size() > k) {window.erase(nums[back++]); }
            
            auto it = window.lower_bound(nums[i] - t);
            if ( it != window.end() ) {
                if ( *it - t <= nums[i] ) {return true;}
            }
            
            window.insert(nums[i]); // NOT inserted until end of loop!!!
        }
        
        return false;
    }
