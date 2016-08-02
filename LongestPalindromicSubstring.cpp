string longestPalindrome(string s) {
        int sz = s.size();
        // vector<vector<bool> > is_pal(sz, vector<bool> (sz, false) );
        // NOT WORKING!!!
        
        bool is_pal [1000][1000] = {false};
        int start = 0, max_len = 1;
        for (int i = sz - 1; i >= 0; i--) {
            for (int j = i; j < sz; j++) {
                if ( ( j - 1 < i + 1  || is_pal[i+1][j-1]) && s[i] == s[j] ) {
                    is_pal[i][j] = true;
                    if (j - i + 1 > max_len) {
                        start = i;
                        max_len = j - i + 1;
                    }
                }
            }
        }

        
        return s.substr(start, max_len);
    }
