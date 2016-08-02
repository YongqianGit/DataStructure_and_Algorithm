bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int cur = x, ten_pow = 1;
        while (cur / 10 > 0) {
            cur /= 10;
            ten_pow *= 10;
        }

        
        while (ten_pow >= 10) {
            int l = x / ten_pow;
            int r = x % 10;
            if (l != r) return false;
            
            x = (x % ten_pow) / 10;
            
            ten_pow /= 100;
            
        }
        
        return true;
        
    }
