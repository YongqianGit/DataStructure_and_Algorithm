string minWindow(string s, string t) {
        vector<int> stat(256, 0), app(256, 0);
        for (char c : t) {
            stat[c]++;
        }
        
        int sz_s = s.size(), sz_t = t.size();
        
        if (sz_s < sz_t) return "";
        
        int cnt = 0;
        int start = 0, final_start = -1, final_tail = sz_s;
        for (int i = 0; i < sz_s; i++) {
            char c = s[i];
            
            if (stat[c] != 0) {
                if (++app[c] <= stat[c]) {cnt++;}
                
                if (cnt == sz_t) {
                    while (stat[ s[start] ] == 0 || app[ s[start] ] > stat[ s[start] ]) {
                        if (stat[ s[start] ] != 0) {app[ s[start] ]--;}
                        start++;
                    }

                    if (i - start < final_tail - final_start) {
                        final_start = start;
                        final_tail = i;
                    }
                    
                    app[ s[start] ]--;
                    start++;
                    cnt--;
                   
                }
                
            }
            
        }
        return final_start == -1? "" : s.substr(final_start, final_tail - final_start + 1);
        // ATENTION!! May NOT exist!!!
    }
