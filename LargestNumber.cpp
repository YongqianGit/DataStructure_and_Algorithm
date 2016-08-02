 bool compare(string s1, string s2) {return s1 + s2 > s2 + s1;}
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> digits;
        
        for (int item : nums) {
            digits.push_back(to_string(item) ) ;
        }
        
        sort(digits.begin(), digits.end(), compare );
        string res;
        for (string item : digits) {
            res += item;
        }
        
        while (res[0] == '0' && res.size() > 1) {
            res.erase(res.begin() );
        }
        
        return res;
    }
