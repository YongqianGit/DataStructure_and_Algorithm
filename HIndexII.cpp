int hIndex(vector<int>& citations) {
        // sz - m <= citations[m]
        int sz = citations.size(), l = 0, r = sz - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ( sz - m > citations[m] ) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return sz - l; // NOT l!!!
    }
