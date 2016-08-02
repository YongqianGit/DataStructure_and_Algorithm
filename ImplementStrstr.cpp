int strStr(string haystack, string needle) {
        int sz_h = haystack.size(), sz_n = needle.size();
        
        if (sz_h < sz_n) return -1;
        
        for (int i = 0; i <= sz_h - sz_n; i++) {
            if (haystack.substr(i, sz_n) == needle ) {return i;} 
        }
        
        return -1;
    }
