void set_zero(vector<vector<int> >& matrix, int sel, bool is_row) {
        if (is_row) {
            for (int c = 0; c < matrix[0].size(); c++) { // set row
                matrix[sel][c] = 0;
            }
        }
        else {
            for (int r = 0; r < matrix.size(); r++) { // set col
                matrix[r][sel] = 0;
            }
        }
    }
    

void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows < 1) {return;}
        int cols = matrix[0].size();
        if (cols < 1) {return;}
        
        bool row0 = false, col0 = false; // whether 1st row/col should be set 0
        
        for (int c = 0; c < cols; c++) { // check orginal 1st row
            if (matrix[0][c] == 0) {row0 = true; break;}
        }
        
        for (int r = 0; r < rows; r++) { //check origianl 1st col
            if (matrix[r][0] == 0) {col0 = true; break;}
        }
        

        
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        
        for (int r = 1; r < rows; r++) { // set rows 0
            if (matrix[r][0] == 0) {
                set_zero(matrix, r, true);
            }
        }
        
        for (int c = 1; c < cols; c++) { // set cols 0
            if (matrix[0][c] == 0) {
                set_zero(matrix, c, false);
            }
        }
        
        if (row0) {
            set_zero(matrix, 0, true);
        }
        
        if (col0) {
            set_zero(matrix, 0, false);
        }
    }
