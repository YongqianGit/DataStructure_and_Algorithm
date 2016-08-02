 int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) return 0;
        int sz = prices.size(), cur_min = prices[0];
        
        int res = 0;
        for (int i = 1; i < sz; i++) {
            if (prices[i] < prices[i-1]) {
                cur_min = min(cur_min, prices[i]);
            }
            else {
                res = max(res, prices[i] - cur_min);
            }
        }
        
        return res;
    }
