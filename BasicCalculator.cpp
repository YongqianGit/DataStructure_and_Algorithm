int calculate(string s) {
        int val = 0;
        stack<int> sign;
        sign.push(1);
        int res = 0, cur_sign = 1;
        s += '+';
        for (char c : s) {
            if ( isspace(c) ) {continue;}
            
            if ( isdigit(c) ) {
                val = val * 10 + c - '0';
            }
            else {
                if (c == '+' || c == '-') {
                    res += val * cur_sign;
                    val = 0;
                    cur_sign = sign.top() * ( c == '+' ? 1 : -1);
                }
                else if (c == '(') {
                    sign.push(cur_sign);
                }
                else if (c == ')') {
                    sign.pop();
                }
            }
        }
        
        
        // res += val * cur_sign;
        return res;
    }
