void gameOfLife(vector<vector<int>>& board) {
        // 0: dead remain dead
        // 1: live remain live
        // 2: live become dead
        // 3: dead become live
        
        int rows = board.size();
        if (rows < 1) {return;}
        int cols = board[0].size();
        if (cols < 1) {return;}
        
        int dx [8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy [8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    if (x >= 0 && x < rows && y >= 0 && y < cols  ) {
                        if (board[x][y] == 1 || board[x][y] == 2) cnt++;
                    }
                }
                
                if (board[i][j] == 1) {
                    if (cnt > 3 || cnt < 2) board[i][j] = 2;
                }
                else {
                    if (cnt == 3) board[i][j] = 3;
                }
                
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] %= 2;
            }
        }
        
        
    }
