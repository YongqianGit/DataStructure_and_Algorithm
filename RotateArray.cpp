void reverse(vector<int> &nums, int l, int r) {
        while (l < r) {
            swap(nums[l++], nums[r--]);
        }
    }


void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz;
        reverse(nums, 0, sz - k - 1);
        reverse(nums, sz - k, sz - 1);
        reverse(nums, 0, sz - 1);
    }
