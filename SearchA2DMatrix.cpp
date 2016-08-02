bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows < 1) return false;
        int cols = matrix[0].size();
        if (cols < 1) return false;
        
        if (target < matrix[0][0] || target > matrix[rows-1][cols-1] ) return false;
        
        
        int t = 0, b = rows - 1;
        while (t <= b) { // search first column for selected row
            int m = t + (b - t) / 2;
            if (matrix[m][0] == target) {return true;}
            else if (target < matrix[m][0]) {
                b = m - 1;
            }
            else { // target > matrix[m][0]
                t = m + 1;
            }
        }
        int r_sel = b;
        
        int l = 0, r = cols - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (matrix[r_sel][m] == target) {return true;}
            else if (target > matrix[r_sel][m]) {
                l = m + 1;
            }
            else { // target <
                r = m - 1;
            }
        }
        
        return false;
    }
