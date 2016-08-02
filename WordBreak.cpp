bool wordBreak(string s, unordered_set<string>& wordDict) {
        int sz = s.size();
        if (sz < 1) return false;
        vector<bool> dp(sz + 1, false);
        // dp[i]: whether s[0:i-1] can be broken or not
        dp[0] = true;
        
        for (int i = 0; i < sz; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] && wordDict.count(s.substr(j, i - j + 1) ) != 0 ) {
                    dp[i + 1] = true; // NOT dp[i]!!!
                }
            }
        }
        
        return dp.back();
    }
