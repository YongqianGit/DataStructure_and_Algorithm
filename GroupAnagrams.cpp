vector<vector<string>> groupAnagrams0(vector<string>& strs) {
        unordered_map<string, unordered_multiset<string> > stat;
        
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end() );
            
            stat[tmp].insert(s);
        }
        
        vector<vector<string> > res;
        for (auto it = stat.begin(); it != stat.end(); it++) {
            vector<string> sol;
            for ( auto it_set = it->second.begin(); it_set != it->second.end(); it_set++ ) {
                sol.push_back(*it_set);
            }
            res.push_back(sol);
        }
        
        return res;
    }


// faster
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > stat;
        
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end() );
            
            stat[tmp].push_back(s);
        }
        
        vector<vector<string> > res;
        for (auto it = stat.begin(); it != stat.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
