bool isIsomorphic(string s, string t) {
        int sz = s.size();
        if (sz != t.size() ) {return false;}
        
        // unordered_map<char, char> m_s, m_t;
        // TOO slow!!
        
        char m_s [256], m_t[256];
        memset(m_s, 0, 256);
        memset(m_t, 0, 256);
        
        for (int i = 0; i < sz; i++) {
            if (m_s[ s[i] ] == 0 && m_t[ t[i] ] == 0 ) {
                m_s[ s[i] ] = t[i];
                m_t[ t[i] ] = s[i];
            }
            else {
                if (m_s[ s[i] ] != t[i] || m_t[ t[i] ] != s[i]) {return false;}
            }
        }
        return true;
    }
