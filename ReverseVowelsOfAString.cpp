bool is_vowel(char in) {
        char c = tolower(in);
        return c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o';
    }


string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while ( l < r && !is_vowel(s[l]) ) {l++;}
            
            while ( r > l && !is_vowel(s[r]) ) {r--;}
            
            if (l >= r) {break;}
            
            swap(s[l++], s[r--]);
            
        }
        
        return s;
    }
