bool isHappy(int n) {
        if (n <= 0) {return false;}
        
        unordered_set<int> stat;
        
        while (n > 1) {
            int cur = 0;
            while ( n > 0) {
                cur += (n % 10) * (n % 10);
                n /= 10;
            } 
            if (cur == 1) {return true;}
            
            if (stat.find(cur) == stat.end() ) {
                stat.insert(cur); 
                n = cur;
            }
            else {return false;}
        }
        
        return n == 1;
        
    }
