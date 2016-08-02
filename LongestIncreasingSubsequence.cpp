#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
        if (nums.empty() ) return 0;
        
        vector<int> dp;
        dp.push_back(nums[0]);
        int sz = nums.size();
        for (int i = 1; i < sz; i++) {
            if (nums[i] > dp.back() ) {
                dp.push_back(nums[i]);
            }
            else {
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return dp.size();
    }

int main(int argc, char** argv) {
      int a [] = {10,9,2,5,3,7,101,18};
      vector<int> nums(a, a + 8);
      cout<<lengthOfLIS(nums)<<endl;
      return 0;
}
