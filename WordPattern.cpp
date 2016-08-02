bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p_s;
        unordered_map<string, char> s_p;
        int ip = 0;
        
        istringstream str_in (str);
        string word;
        
        while (str_in >> word) {
            if (ip >= pattern.size() ) return false; // pattern NOT longer enough
            
            if (p_s.find( pattern[ip] ) == p_s.end() && s_p.find( word ) == s_p.end() ) {
                p_s[ pattern[ip] ] = word;
                s_p[ word ] = pattern[ip];
            }
            else {
                if (p_s[ pattern[ip] ] != word || s_p[ word ] != pattern[ip]) {return false;}
            }
            ip++;
        }
        
        return ip == pattern.size();// avoid pattern too long
    }
