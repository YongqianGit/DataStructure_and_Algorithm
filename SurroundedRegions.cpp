void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows < 2) return;
        int cols = board[0].size();
        if (cols < 2) return;
        
        stack<pair<int, int> > bc;
        
        for (int r = 0; r < rows; r++) { // left & right edges
            if (board[r][0] == 'O') bc.push( make_pair(r, 0) );
            if (board[r][cols - 1] == 'O') bc.push( make_pair(r, cols - 1) ); 
        }
        
        for (int c = 0; c < cols; c++) { // top & bot edges
            if (board[0][c] == 'O') bc.push( make_pair(0, c) );
            if (board[rows - 1][c] == 'O') bc.push( make_pair(rows - 1, c) );
        }
        
        while (!bc.empty() ) {
            int r = bc.top().first;
            int c = bc.top().second;
            board[r][c] = 'Y';
            bc.pop();
            
            if (r > 0 && board[r-1][c] == 'O') {bc.push( make_pair(r-1, c) );}
            if (r < rows - 1 && board[r+1][c] == 'O') {bc.push( make_pair(r+1, c) );}
            if (c > 0 && board[r][c-1] == 'O') {bc.push( make_pair(r, c-1) );}
            if (c < cols - 1 && board[r][c+1] == 'O') {bc.push( make_pair(r, c+1) );}
        }
        
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'Y') board[r][c] = 'O';
            }
        }
        
    }
