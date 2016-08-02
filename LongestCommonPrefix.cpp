string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() ) {return "";}
        
        int sz = strs.size(), sz0 = strs[0].size();
        
        
        string res;
        for (int i = 0; i < sz0; i++) { // iterate ove strs[0]
            char c = strs[0][i];
            for (int j = 1; j < sz; j++) { // iterate over strs
                if (i > strs[j].size() || strs[j][i] != c) {
                    return res;
                }
            }
            res += c;
        }
        
        return res;
    }
