int myAtoi(string str) {
        int sz = str.size();
        int it = 0;
        while (it < sz && str[it] == ' ') {it++;}
        
        // if (it == sz) {return 0;}
        
        bool is_neg = false;
        if (str[it] == '+' || str[it] == '-') {
            is_neg = str[it] == '-'? true : false;
            it++;
        }
        
        unsigned long long val = 0;
        while (it < sz) {
            if (!isdigit(str[it]) ) {break;}
            val = val * 10 + (str[it] - '0');
            if (val > INT_MAX) {return is_neg? INT_MIN : INT_MAX;}
            it++;
        }
        
        return is_neg? -val : val;
        
    }
