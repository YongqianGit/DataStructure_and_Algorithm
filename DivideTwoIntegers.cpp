int divide(int dividend, int divisor) {
        if (divisor == 0) {return dividend < 0? INT_MIN : INT_MAX;}
        if (dividend == 0) {return 0;}
        if (divisor == - 1 && dividend == INT_MIN) {return INT_MAX;}
        if (divisor == 1) {return dividend;}
        
        bool is_neg = (dividend < 0 ^ divisor < 0);
        
        long long dvd = dividend, dor = divisor;
        dvd = abs(dvd); dor = abs(dor);
        
        int cnt = 0;
        while (dvd>>(cnt+1) >=dor ) {
            cnt++;
        }
        
        int res = 0;
        while (dvd >= dor && cnt >= 0 ) {
            if (dvd >= dor<<cnt) {
                res += 1<<cnt;
                dvd -= dor<<cnt;
            }
            cnt--;
        }
        
        return is_neg ? -res : res;
    }
