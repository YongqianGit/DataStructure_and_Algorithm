bool isPalindrome(string s) {
        int sz = s.size();
        int l = 0, r = sz - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l]) ) {l++;}
            
            while (r > l && !isalnum(s[r]) ) {r--;}
            
            if (tolower(s[l]) != tolower(s[r]) ) {
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
