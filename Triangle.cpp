 int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (rows < 1) return 0;
        int cols = triangle[0].size();
        if (cols < 1) return 0;
        
        if (rows == 1) {return triangle[0][0];}
        
        vector<int> dp(rows, INT_MAX), dp_prev(rows, INT_MAX);
        dp[0] = dp_prev[0] = triangle[0][0];
        
        for (int r = 1; r < rows; r++) {
            
            dp[0] = dp_prev[0] + triangle[r][0];
            dp[r] = dp_prev[r - 1] + triangle[r][r];
            for (int c = 1; c < r; c++) {
                dp[c] = min(dp_prev[c - 1], dp_prev[c]) + triangle[r][c];
            }
            dp_prev = dp;
        }
        
        int res = INT_MAX;
        for (int item : dp) {
            res = min(item, res);
        }
        
        return res;
    }
