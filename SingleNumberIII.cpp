vector<int> singleNumber0(vector<int>& nums) {
        unordered_map<int, int> stat;
        for (int item : nums) {
            if (++stat[item] == 2) {stat.erase(item);}
        }
        
        vector<int> res;

        res.push_back(stat.begin()->first);
        res.push_back( ( ++stat.begin() )->first);
        
        return res;
    }
    
    // Same performance
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> stat;
        
        for (int item : nums) {
            if (stat.find(item) == stat.end() ) {
                stat.insert(item);
            }
            else {
                stat.erase(item);
            }
        }
        
        vector<int> res(2);
        res[0] = *stat.begin();
        res[1] = *(++stat.begin() );
        
        return res;
    }
