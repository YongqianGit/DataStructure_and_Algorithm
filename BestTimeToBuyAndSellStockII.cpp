int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int sz = prices.size();
        for (int i = 1; i < sz; i++) {
            if (prices[i] > prices[i-1]) {
                max_prof += prices[i] - prices[i-1];
            }
        }
        
        return max_prof;
    }
