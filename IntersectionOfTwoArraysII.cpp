vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end() );
        sort(nums2.begin(), nums2.end() );
        for (auto it1 = nums1.begin(), it2 = nums2.begin(); \
        it1 != nums1.end() && it2 != nums2.end(); ) {
            if (*it1 == *it2) {
                res.push_back(*it1);
                it1++;
                it2++;
            }
            else if (*it1 < *it2) {
                it1 = lower_bound(it1, nums1.end(), *it2);
            }
            else {
                it2 = lower_bound(it2, nums2.end(), *it1);
            }
        }
        
        return res;
    }
