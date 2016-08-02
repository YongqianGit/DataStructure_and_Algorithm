#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int maxSubArray(vector<int>& nums) {
        
        
        if (nums.empty() ) return 0;
        
        int sum = nums[0], cur_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            cur_max = max(cur_max + nums[i], nums[i]);
            
            sum = max(cur_max, sum);
        }
        
        return sum;
        
    }

int main() {
      int a [] = {-2,1,-3,4,-1,2,1,-5,4};
      vector<int> nums(a, a + 9);
      cout<<maxSubArray(nums)<<endl;
      return 0;
}
