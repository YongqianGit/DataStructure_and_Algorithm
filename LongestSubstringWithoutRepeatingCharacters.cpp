int lengthOfLongestSubstring(string s) {
        int sz = s.size(), max_len = 0;
        if (sz < 1) return 0;
        vector<int> stat(256, -1);
        int start = -1;
        for (int i = 0; i < sz; i++) {
            char c = s[i];
            if (stat[c] != -1 && start < stat[c] ) {
                start = stat[ c ];
            }
            
            max_len = max(max_len, i - start);
            stat[c] = i;
        }
        
        return max_len;
        
    }
