// time(n), space(n)
    int findDuplicate(vector<int>& nums) {
        int sz = nums.size();
        bool stat [sz];
        memset(stat, false, sizeof stat);
        for (int item : nums) {
            if (stat[item] ) {return item;}
            else {stat[item] = true;}
        }
        
        return -1;
    }
    
    // time(n^2), space(1)
    int findDuplicate1(vector<int>& nums) {
        int sz = nums.size(), l = 1, r = sz - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            int le = 0;
            
            for (int item : nums) {
                if (item <= m) {le++;}
            }
            
            if (le > m) {r = m - 1;}
            else {l = m + 1;}
        }
        
        return l;
    }
