int singleNumber(vector<int>& nums) {
        unordered_map<int, int> stat;
        for (int item : nums) {
            if (++stat[item] == 3) {stat.erase(item);}
        }
        
        return stat.begin()->first;
    }
