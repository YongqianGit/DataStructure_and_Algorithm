string addBinary(string a, string b) {
        reverse(a.begin(), a.end() );
        reverse(b.begin(), b.end() );
        
        int sz_a = a.size(), sz_b = b.size();
        int ia = 0, ib = 0, carry = 0;
        string res;
        while (ia < sz_a && ib < sz_b) {
            int cur = (a[ia] - '0') + (b[ib] - '0') + carry;
            res.insert(res.begin(), cur % 2 + '0');
            carry = cur / 2;
            ia++;
            ib++;
        }
        
        while (ia < sz_a) {
            int cur = a[ia++] - '0' + carry;
            res.insert(res.begin(), cur % 2 + '0');
            carry = cur / 2;
        }
        
        while (ib < sz_b) {
            int cur = b[ib++] - '0' + carry;
            res.insert(res.begin(), cur % 2 + '0');
            carry = cur / 2;
        }
        
        if (carry != 0) {
            res.insert(res.begin(), '1');
        }
        
        return res;
    }
