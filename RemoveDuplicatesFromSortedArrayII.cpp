#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        
        int sz = nums.size();
        if (sz < 1) return 0;
        
        int pos = 1, cnt = 1;
        for (int i = 1; i < sz; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[pos++] = nums[i];
                cnt = 1;
            }
            else {
                if (++cnt <= 2) {
                    nums[pos++] = nums[i];
                } 
            }
            // if ( (nums[i] != nums[i-1]) || (nums[i] == nums[i-1] && ++cnt <= 2) ) {
            //   if (nums[i] != nums[i-1]) {cnt = 1;}
            //   nums[pos++] = nums[i];
            // }
        }
        
        return pos;
}

int main(int argc, char** argv) {
      int a [] = {1,1,1,1,3,3};
      vector<int> nums(a, a + 6);
      cout<<removeDuplicates(nums)<<endl;
      return 0;
}
