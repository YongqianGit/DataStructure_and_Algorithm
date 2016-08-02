// f(n) == f(n-1)*f(0) + f(n-2)*f(1) ...+ f(0)*f(n-1)
    // f(0) = f(1) = 1;
    int numTrees(int n) {
        if (n < 2) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        
        return dp[n];
    }
