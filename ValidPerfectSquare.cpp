bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        
        int l = 1, r = num;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            if (num / m == m) {return m * m == num;}
            
            else if (num / m < m) { // m too high
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return l * l == num;
    }
