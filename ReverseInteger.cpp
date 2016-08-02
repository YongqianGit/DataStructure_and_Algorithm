int reverse(int x) {
        unsigned long long cur = abs(x), res = 0;
        
        bool is_neg = x < 0 ? true : false;
       
        while (cur > 0) {
            res = res * 10 + cur % 10;
            
            if (res > INT_MAX) {return 0;}
            
            cur /= 10;
        }
        
        return is_neg? -res : res;
    }
