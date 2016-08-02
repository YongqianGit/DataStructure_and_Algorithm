int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows < 1) {return 0;}
        int cols = grid[0].size();
        if (cols < 1) {return 0;}
        
        
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) {return 0;}
        // no entrance or exit
        
        vector<int> dp(cols, 0);
        
        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 1) {break;}
            else {dp[c] = 1;}
        } // first row
        
        for (int r = 1; r < rows; r++) {
            dp[0] = grid[r][0] == 1 ? 0 : dp[0]; // once 1 obstable in first column, the whole column is blocked!
            for (int c = 1; c < cols; c++) {
                if (grid[r][c] == 1) {
                    dp[c] = 0;
                }
                else {
                    dp[c] = dp[c-1] + dp[c];
                }
            }
        }
        
        return dp.back();
    }
