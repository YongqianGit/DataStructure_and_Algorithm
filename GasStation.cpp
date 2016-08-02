int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();
        if (sz != cost.size() ) return -1;
        int cur = 0, all = 0;
        int s = 0;
        for (int i = 0; i < sz; i++) {
            cur += gas[i] - cost[i];
            all += gas[i] - cost[i];
            if (cur < 0) {
                s = i + 1;
                cur = 0;
            }
        }
        
        return all >= 0? s: -1;
    }
