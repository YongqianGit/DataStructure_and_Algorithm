int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows < 1) {return 0;}
        int cols = grid[0].size();
        if (cols < 1) {return 0;}
        
        vector<int> dp(cols, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < rows; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < cols; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        
        return dp.back();
    }
