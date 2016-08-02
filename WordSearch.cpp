bool search(vector<vector<char> >& board, int r, int c, \
    int cnt, string& word, vector<vector<bool> >& visit) {
        
        if (cnt == word.size() ) {
            return true;
        }
        
        int rows = board.size(), cols = board[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || visit[r][c] || board[r][c] != word[cnt]) {
            return false;
        }

        visit[r][c] = true;
        
        if (search(board, r+1, c, cnt+1, word, visit) ) {return true;}
        if (search(board, r-1, c, cnt+1, word, visit) ) {return true;}
        if (search(board, r, c+1, cnt+1, word, visit) ) {return true;}
        if (search(board, r, c-1, cnt+1, word, visit) ) {return true;}
        
        visit[r][c] = false;
        
        return false;
        
    }

bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows < 1) return false;
        int cols = board[0].size();
        if (cols < 1) return false;
        
        vector<vector<bool> > visit(rows, vector<bool> (cols, false) );
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0]) {
                    if ( search(board, r, c, 0, word, visit) ) return true;
                }
            }
        }
        
        return false;
    }
