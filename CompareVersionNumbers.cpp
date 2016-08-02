 int compareVersion(string v1, string v2) {
        int sz1 = v1.size(), sz2 = v2.size();
        int i1 = 0, i2 = 0;
        while (i1 < sz1 && i2 < sz2) {
            int val1 = 0;
            while (i1 < sz1 && v1[i1] != '.') {val1 = val1 * 10 + v1[i1] - '0'; i1++;}
            
            int val2 = 0;
            while (i2 < sz2 && v2[i2] != '.') {val2 = val2 * 10 + v2[i2] - '0'; i2++;}

            if (val1 > val2) {return 1;}
            else if (val1 < val2) {return -1;}
            
            i1++;
            i2++;
        }
        
        while (i1 < sz1) {
            if (v1[i1] != '0' && v1[i1] != '.') {return 1;}
            i1++;
        }
        
        while (i2 < sz2) {
            if (v2[i2] != '0' && v2[i2] != '.') {return -1;}
            i2++;
        }
        
        return 0;
    }
