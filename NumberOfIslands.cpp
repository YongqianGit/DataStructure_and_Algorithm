void search (vector<vector<char> >& grid, int r, int c) {
        int rows = grid.size(), cols = grid[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') {
            return;
        }
        
        grid[r][c] = 'X';
        
        search(grid, r + 1, c);
        search(grid, r - 1, c);
        search(grid, r, c + 1);
        search(grid, r, c - 1);
        
    }

int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows < 1) {return 0;}
        int cols = grid[0].size();
        if (cols < 1) {return 0;}
        
        int cnt = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    search(grid, r, c);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
