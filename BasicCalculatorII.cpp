int calculate(string s) {
        int cur_sign = 1;
        stack<int> sign;
        istringstream str_in (s + '+');
        char op;
        int val;
        str_in >> val; 
        int res = 0;
        
        while (str_in >> op) {
            if (op == '+' || op == '-') {
                res += val * cur_sign;
                
                cur_sign = op == '+' ? 1 : -1;
                
                str_in >> val;
                 
            }
            else {
                int next_val;
                str_in >> next_val;
               
                if (op == '*') {
                    val = val * next_val;
                }
                else {
                    val = val / next_val;
                }
            }
        }
        
        return res;
     }
