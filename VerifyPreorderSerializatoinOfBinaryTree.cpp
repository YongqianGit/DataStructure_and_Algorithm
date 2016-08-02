bool isValidSerialization(string preorder) {
        int in_deg = 1;
        istringstream str_in (preorder);
        
        string cur;
        while (getline(str_in, cur, ',') ) {
            in_deg--;
            if (in_deg < 0) return false;
            
            if (cur != "#") {
                in_deg += 2;
            }
        }
        
        return in_deg == 0;
    }
