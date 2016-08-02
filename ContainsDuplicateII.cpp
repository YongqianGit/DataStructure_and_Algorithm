bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> stat;
        int back = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (stat.size() > k) {stat.erase(nums[back++]); }
            
            auto it = stat.find(nums[i]);
            
            if (it != stat.end() ) {return true;}
            
            stat.insert(nums[i]);
        }
        
        return false;
    }
