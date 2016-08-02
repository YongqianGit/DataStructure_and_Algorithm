vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size(), carry = 1;
        vector<int> res;
        
        for (int i = sz - 1; i>= 0; i--) {
            int cur = digits[i] + carry;
            res.insert(res.begin(), cur % 10);
            carry = cur / 10;
        }
        
        if (carry != 0) {
            res.insert(res.begin(), 1);
        }
        
        return res;
    }
