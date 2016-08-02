int nthUglyNumber(int n) {
        int pos2 = 0, pos3 = 0, pos5 = 0;
        vector<int> ugly(n, 0);
        ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            int min_cur = min( min(2 * ugly[pos2], 3 * ugly[pos3]), 5 * ugly[pos5] );
            ugly[i] = min_cur;
            
            if (min_cur % 2 == 0) {pos2++;}
            if (min_cur % 3 == 0) {pos3++;}
            if (min_cur % 5 == 0) {pos5++;}
        }
        
        return ugly.back();
    }
