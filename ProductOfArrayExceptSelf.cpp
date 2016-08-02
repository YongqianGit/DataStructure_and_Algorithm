#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int cnt0 = 0;
        int sz = nums.size();
        long long prod = 1;
        vector<int> res(sz, 0);
        
        for (int i = 0; i < sz; i++) {
            int item = nums[i];
            if (item == 0) {
                if (++cnt0 > 1) {return res;} 
            }
            else {
                prod *= item;
            }
        }
        
        for (int i = 0; i < sz; i++) {
            if (cnt0 == 0) {
                res[i] = prod / nums[i];
            }
            else {
                res[i] = nums[i] == 0? prod : 0;
            }
        }
         
        return res;
    }

int main(int argc, char** argv) {
      int a [] = {0,1,2,3,4};
      vector<int> nums(a, a + 5);
      vector<int> res = productExceptSelf(nums);
      for (int i = 0; i < res.size(); i++) {
            cout<< res[i]<<" ";
      }
      cout<<endl;
      return 0;
}
