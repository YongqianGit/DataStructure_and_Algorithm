vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> stat;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = stat.find(target - nums[i]);
            if (it != stat.end() ) {
                res.push_back(stat[target - nums[i] ]);
                res.push_back(i);
                break;
            }
            else {
                stat[ nums[i] ] = i;
            }
        }
        
        return res;
    }
