// non-negative.
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0") {return "0";}
        
        int sz1 = num1.size(), sz2 = num2.size();
        string res (sz1 + sz2, '0');
        reverse(num1.begin(), num1.end() );
        reverse(num2.begin(), num2.end() );
        
        
        for (int i2 = 0; i2 < sz2; i2++) {
            int carry = 0;
            for (int i1 = 0; i1 < sz1; i1++) {
                int cur = carry + (num1[i1] - '0') * (num2[i2] - '0') + res[i1 + i2] - '0';
                res[i1 + i2] = cur % 10 + '0';
                carry = cur / 10;
            }
           if (carry != 0) {
                res[i2 + sz1] = carry % 10 + '0';
            }
        }
        
        reverse(res.begin(), res.end() );
        
        while (res[0] == '0' && res.size() > 1) {res.erase(res.begin() );}
        return res;
    }
