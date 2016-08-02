int hIndex(vector<int>& citations) {
        int sz = citations.size();
        vector<int> stat(sz + 1, 0);
        
        for (int item : citations) {
            if (item > sz) {stat[sz]++;}
            else {stat[item]++;}
        }
        
        int sum = 0;
        
        for (int i = sz; i >= 0; i--) {
            sum += stat[i];
            if (sum >= i) {return i;}
        }
        
        return sum;
    }
