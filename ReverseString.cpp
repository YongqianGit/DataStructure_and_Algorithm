string reverseString(string s) {
        int sz = s.size(), l = 0, r = sz - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
        
        return s;
    }
