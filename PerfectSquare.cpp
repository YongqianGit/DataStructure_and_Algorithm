int numSquares(int n) {
        while ( n > 0 ) {
            if (n % 4 == 0) n /= 4;
            else {break;}
        }
        
        if ( n % 8 == 7) {return 4;}
        
        for (int i = 0; i * i <= n; i++) {
            int num2 = sqrt( n - i * i );
            if (i * i + num2 * num2 == n) {
                return !!i + !!num2;
            }
        }
        
        return 3;
    }
