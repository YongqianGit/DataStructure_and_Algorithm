vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows < 1) {return {}; }
        int cols = matrix[0].size();
        if (cols < 1) {return {}; }
        
        vector<int> res;
        int l = 0, r = cols - 1, t = 0, b = rows - 1;
        while (true) {
            
            for (int i = l; i <= r; i++) { // top
                res.push_back(matrix[t][i]);
            }
            if (++t > b) {break;}
            
            for (int i = t; i <= b; i++) { // right
                res.push_back(matrix[i][r]);
            }
            if (--r < l) {break;}
            
            for (int i = r; i >= l; i--) { // bot
                res.push_back(matrix[b][i]);
            }
            if (--b < t) {break;}
            
            for (int i = b; i >= t; i--) { // left
                res.push_back(matrix[i][l]);
            }
            if (++l > r) {break;}
        }
        
        return res;
    }
