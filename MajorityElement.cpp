int majorityElement(vector<int>& nums) {
        int cnt = 0, m = 0;
        
        for (int item : nums) {
            if (item == m) {
                cnt++;
            }
            else if (cnt == 0) {
                m = item;
                cnt = 1;
            }
            else {
                cnt--;
            }
        }
        
        return m;
    }
