bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows < 1) {return false;}
        int cols = matrix[0].size();
        if (cols < 1) {return false;}
        
        int r = 0, c = cols - 1;// start from right top conner
        
        while (r < rows && c >= 0) {
            if (matrix[r][c] == target) {return true;}
            
            else if (matrix[r][c] < target) {
                r++;
            }
            
            else {
                c--;
            }
        }
        
        return false;
    }
