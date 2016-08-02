int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz_p = primes.size();
        vector<int> pos(sz_p, 0);
        vector<int> ugly(n, 0);
        ugly[0] = 1;
        
        for (int i = 1; i < n; i++) {
            int cur_min = INT_MAX;
            for (int j = 0; j < sz_p; j++) {
                cur_min = min( cur_min, primes[j] * ugly[ pos[j] ] );
            }
            
            ugly[i] = cur_min;
            
            for (int j = 0; j < sz_p; j++) {
                if (cur_min % primes[j] == 0) {
                    pos[j]++;
                }
            }
        }
        
        return ugly.back();
    }
