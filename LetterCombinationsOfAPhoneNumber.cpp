vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty() ) return res;
        res.push_back("");
        string dict [10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for (char c : digits) {
            int sz_res = res.size(), id = c - '0';
            for (int i = 0; i < sz_res; i++) {
                
                for (int j = 1; j < dict[id].size(); j++) {
                    string cur = res[i];
                    cur += dict[id][j];
                    res.push_back(cur);
                }
                res[i] += dict[id][0];
            }
            
        }
        
        return res;
    }
