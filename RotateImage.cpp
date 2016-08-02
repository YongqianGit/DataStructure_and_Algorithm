void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int s = 0, e = n - 1;
        
        while (s < e) {
            for (int i = s; i < e; i++) {
                int offset = i - s;
                int tmp_lt = matrix[s][s + offset];
                matrix[s][s + offset] = matrix[e - offset][s];
                matrix[e - offset][s] = matrix[e][e - offset];
                matrix[e][e - offset] = matrix[s + offset][e];
                matrix[s + offset][e] = tmp_lt;
            }
            s++;
            e--;
        }
    }
