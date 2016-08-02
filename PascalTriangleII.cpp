vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        if (rowIndex < 2) {return res;}
        
        unsigned long long cur = 1;
        for (int i = 1; i <= rowIndex / 2; i++) {
            cur = cur * (rowIndex - i + 1) / i;
            res[i] = res[rowIndex - i] = cur;
        }
        
        return res;
    }
