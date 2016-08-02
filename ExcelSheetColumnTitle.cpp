string convertToTitle(int n) {
        string res;
        while (n > 0) {
            int dig = n % 26;
            
            if (dig == 0) {
                res.insert(res.begin(), 'Z');
                n--;// IMPORTANT!!!
            }
            else {
                res.insert(res.begin(), dig + 'A' - 1);
            }
            
            n /= 26;
        }
        
        return res;
    }
