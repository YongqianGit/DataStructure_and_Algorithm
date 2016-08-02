// each word in words exactly once and without any intervening characters. 
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int sz_s = s.size(), sz_ws = words.size(), len_w = words[0].size();
        
        if (sz_s < sz_ws * len_w) {return res;}
        
        unordered_map<string, int> stat;
        for (string w : words) {
            stat[w]++;
        }
        
        for (int i = 0; i < len_w; i++) {
            int cnt = 0;
            int left_most = i;
            unordered_map<string, int> stat_cur;
            for (int j = i; j <= sz_s - len_w; j += len_w) {
                string cur = s.substr(j, len_w);
                
                if ( stat.find(cur) == stat.end() ) {
                    stat_cur.clear();
                    left_most = j + len_w;
                    cnt = 0;
                    continue;
                }
                
                cnt++;
                if (++stat_cur[cur] > stat[cur]) {
                    string tmp;
                    do {
                        tmp = s.substr(left_most, len_w);
                        left_most += len_w;
                        cnt--;
                        stat_cur[tmp]--;
                    } while (tmp != cur);
                    
                }
              
                if (cnt == sz_ws) {
                    res.push_back(left_most);
                    cnt--;
                    stat_cur[ s.substr(left_most, len_w) ]--;
                    left_most += len_w;
                    
                }
                
            }
        }
        
        return res;
    }
