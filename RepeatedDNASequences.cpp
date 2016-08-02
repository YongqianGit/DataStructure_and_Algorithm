vector<string> findRepeatedDnaSequences(string s) {
        int sz = s.size();
        vector<string> res;
        if (sz < 11) return res;
        unordered_map<string, int> stat;
        
        for (int i = 0; i <= sz - 10; i++) {
            string cur = s.substr(i, 10);
            if (++stat[cur] == 2) {res.push_back(cur);}
        }
        
        return res;
    }
