int maxArea(vector<int>& height) {
        int sz = height.size();
        int l = 0, r = sz - 1;
        int res = 0;
        
        while (l <= r) {
            res = max(res, (r - l) * min(height[l], height[r]) );
            if (height[l] < height[r]) {
                l++;
            }
            else if (height[l] > height[r]) {
                r--;
            }
            else { // ==
                l++;
                r--;
            }
        }
        
        return res;
    }
