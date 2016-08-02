int countPrimes(int n) {
        // 0 and 1 are NOT primes...
        
        // vector<bool> is_prime(n, true);
        // is_prime[0] = is_prime[1] = false;
        
        bool is_prime [n];
        memset(is_prime, true, sizeof is_prime);
        is_prime[0] = is_prime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (!is_prime[i]) {continue;}
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (is_prime[i]) cnt++;
        }
        
        return cnt;
    }
