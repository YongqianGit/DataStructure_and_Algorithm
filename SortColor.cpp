#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortColors(vector<int>& nums) {
        int sz = nums.size();
        int l = 0, r = sz - 1;
        for (int i = 0; i <= r;) {
            if (nums[i] == 2) {
                swap(nums[i], nums[r--]);
            } 
            else if (nums[i] == 0) {
                swap(nums[i], nums[l++]);
                i++;
            }
            else {i++;}
        }
    }

int main(int argc, char** argv) {
      int a [] = {0,1,0,2,1};
      vector<int> nums(a, a + 5);
      sortColors(nums);
      for (int i = 0; i < nums.size(); i++) {
            cout<<nums[i]<<" ";
      }
      cout<<endl;
      return 0;
}
