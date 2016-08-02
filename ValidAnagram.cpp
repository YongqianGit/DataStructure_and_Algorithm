bool isAnagram0(string s, string t) {
        int sz = s.size();
        if (sz != t.size() ) {return false;}
        
        unordered_map<char, int> stat;
        for (int i = 0; i < sz; i++) {
            stat[ s[i] ]++;
            stat[ t[i] ]--;
        }
        
        for (auto it = stat.begin(); it != stat.end(); it++) {
            if (it->second != 0) return false;
        }
        
        return true;
    }
    
    // Faster NOT using unordered_map!!!
    bool isAnagram(string s, string t) {
        int sz = s.size();
        if (sz != t.size() ) {return false;}
        
        int stat [26];
        memset(stat, 0, sizeof stat);
        
        for (int i = 0; i < sz; i++) {
            stat[ s[i] - 'a' ]++;
            stat[ t[i] - 'a' ]--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (stat[i] != 0) return false;
        }
        
        return true;
    }
