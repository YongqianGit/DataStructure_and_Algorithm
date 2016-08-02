#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        int sz = nums.size();
        sort(nums.begin(), nums.end() );
        int min_diff = INT_MAX;
        for (int i = 0; i < sz - 2; i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int l = i + 1, r = sz - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) {return target;}
                
                if ( abs(min_diff) > abs(sum - target) ) {min_diff = sum - target;}
                
                if (target > sum) {l++;}
                else {r--;}
                
                // while (l < r && nums[l-1] == nums[l]) {l++;}
                // while (r > l && nums[r+1] == nums[r]) {r--;}
                
            }
        }
        
        return min_diff + target;
    }

int main(int argc, char** argv) {
      int a[] = {1,1,-1,-1,3}, target = -1;
      vector<int> nums(a, a +5);
      cout<<threeSumClosest(nums, target)<<endl;
      return 0;
}
