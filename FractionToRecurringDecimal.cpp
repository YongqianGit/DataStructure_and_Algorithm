string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {return numerator < 0? to_string(INT_MIN) : to_string(INT_MAX);}
        // if (numerator == INT_MIN && denominator == -1) {return to_string(INT_MAX);}
        if (denominator == 1) {return to_string(numerator);}
        if (numerator == 0) {return "0";}
        
        bool is_neg = (numerator < 0 ^ denominator < 0);
        
        long long dvd = numerator, dor = denominator;
        dvd = abs(dvd); dor = abs(dor);
        
        string res = is_neg? "-" : "";
        
        
        res += to_string(dvd / dor);
        unordered_map<int, int> digit;
        dvd %= dor;
        
        
        if (dvd == 0) return res;
        else {res += '.';}
        
        while (dvd > 0) {
            if (digit.find(dvd) != digit.end() ) { // start recurring
                res.insert(digit[dvd], "(");
                res+= ')';
                break;
            }
            
            digit[dvd] = res.size();
            int cur = dvd * 10 / dor;
            res += to_string(cur);
            dvd = (dvd * 10) % dor;
            
        }
        
        return res;
        
    }
