// https://discuss.leetcode.com/topic/30421/share-my-thinking-process/48
    // Read the discussion!!!
    int maxProfit(vector<int>& prices) {
        // buy[i] = max(buy[i-1], cool[i-1] - price)
        // sell[i] = max(sell[i-1], buy[i-1] + price)
        // cool[i] = max(cool[i-1], sell[i-1], buy[i-1])
        // Because cool[i] = sell[i-1]
        // So buy[i] = max(buy[i-1], sell[i-2] - price)
        // sell[i] = max(sell[i-1], buy[i-1] + price)
        
        int sell = 0, sell_pre = 0;
        int buy = INT_MIN, buy_pre = INT_MIN;
        for (int item : prices) {
            buy_pre = buy;
            buy = max(buy_pre, sell_pre - item);
            sell_pre = sell;
            sell = max(sell_pre, buy_pre + item);
            
        }
        
        return sell;
    }
