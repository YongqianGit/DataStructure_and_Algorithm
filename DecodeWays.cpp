int numDecodings(string s) {
        int sz = s.size();
        
        if (sz < 1 || s[0] < '1') return 0;
        
        vector<int> dp(sz + 1, 0);
        dp[0] = dp[1] = 1;
        
        for (int i = 1; i < sz; i++) {
            int val = (s[i-1] - '0') * 10 + s[i] - '0';
            if (val > 9 && val < 27) {dp[i + 1] = dp[i-1];}
            
            if (s[i] != '0') {
                dp[i+1] += dp[i];
            }
            
            if (dp[i + 1] == 0) {return 0;}
            
        }
        
        return dp[sz];
    }
