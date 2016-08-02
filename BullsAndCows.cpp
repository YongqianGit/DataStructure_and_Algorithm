string getHint(string secret, string guess) {
        int sz = secret.size();
        if (sz != guess.size() ) {return "";}
        
        int stat [10];
        memset(stat, 0, sizeof stat);
        // MUST use 'sizeof', NOT just the count!!!!
        
        // vector<int> stat(10, 0);
        
        int bull = 0, cow = 0;
        for (int i = 0; i < sz; i++) {
            if (secret[i] == guess[i]) {bull++;}
            else {
                if ( stat[ secret[i] - '0' ]++ < 0 ) {cow++;}
                if ( stat[ guess[i] - '0' ]-- > 0 ) {cow++;}
            }
        }
        
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
