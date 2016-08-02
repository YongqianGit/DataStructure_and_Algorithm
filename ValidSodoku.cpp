bool isValidSudoku(vector<vector<char>>& board) {
        
        
        
        for (int i = 0; i < 9; i++) {
            vector<bool> row (9, false), col (9, false), cell (9, false);
            
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') { // check ith row
                    if ( row[ board[i][j] - '0' ] ) {return false;}
                    else {row[ board[i][j] - '0' ] = true;}
                }
                
                if (board[j][i] != '.') { // check ith column
                    if ( col[ board[j][i] - '0' ] ) {return false;}
                    else {col[ board[j][i] - '0' ] = true;}
                }
                
                // 9 cells, ith one!!
                int r = i / 3 * 3 + j / 3, c = (i % 3) * 3 + j % 3;
                if (board[r][c] != '.') { // check cell
                    if ( cell[ board[r][c] - '0' ] ) {return false;}
                    else {cell[ board[r][c] - '0' ] = true;}
                }
                
            }
        }
        
        return true;
    }
