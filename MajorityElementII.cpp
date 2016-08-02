vector<int> majorityElement(vector<int>& nums) {
        int m1 = 0, m2 = 0, cnt1 = 0, cnt2 = 0;
        
        int sz = nums.size();
        
        for (int i = 0; i < sz; i++) {
            if (nums[i] == m1) {
                cnt1++;
            }
            else if (nums[i] == m2) {
                cnt2++;
            }
            else if (cnt1 - 1 < 0) {
                m1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 - 1 < 0) {
                m2 = nums[i];
                cnt2 = 1;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        
        cnt1 = cnt2 = 0;
        for (int item : nums) {
            if (item == m1) {cnt1++;}
            else if (item == m2) {cnt2++;}
        }
        
        vector<int> res;
        if (cnt1 > sz / 3) {res.push_back(m1);}
        if (cnt2 > sz / 3) {res.push_back(m2);}
        
        return res;
    }
