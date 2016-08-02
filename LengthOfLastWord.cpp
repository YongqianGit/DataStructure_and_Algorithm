//  consists of upper/lower-case alphabets and empty space characters ' '
    int lengthOfLastWord(string s) {
        istringstream str_in (s);
        string word;
        
        while (str_in >> word) {}
        
        return word.size();
    }
