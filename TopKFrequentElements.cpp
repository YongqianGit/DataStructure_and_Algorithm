vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> stat;
        // <val, count>
        
        for (int item : nums) {
            stat[item]++;
        }
        
        vector<int> res;
        
        priority_queue< pair<int, int> > heap;
        // <count, val>
        
        for (auto it = stat.begin(); it != stat.end(); it++) {
            heap.push(make_pair(it->second, it->first) );
        }
        
        while (k-- > 0) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        
        return res;
    }
