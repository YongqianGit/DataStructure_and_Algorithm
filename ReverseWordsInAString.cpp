void reverseWords(string &s) {
        string res;
        string word;
        istringstream str_in (s);
        while (str_in >> word) {
            if (res.empty() ) {
                res = word;
            }
            else {
                res.insert(0, word + ' ');
            }
        }
        
        s = res;
    }
