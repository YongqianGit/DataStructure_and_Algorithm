#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

 int minSubArrayLen0(int s, vector<int>& nums) {
        queue<int> window;
        int sz = nums.size();
        int min_sz = INT_MAX, sum = 0;
        bool found;
        for (int i = 0; i < sz; i++) {
            sum += nums[i];
            window.push(nums[i]);
            found = false;
            while (sum >= s) {
                found = true;
                if (!window.empty() ) {
                    sum -= window.front();
                    window.pop();
                }
            }
            if (found && min_sz > window.size() + 1) { min_sz = window.size() + 1;}
        }
        
        return min_sz != INT_MAX?  min_sz : 0;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();
        int back = 0, min_sz = INT_MAX, sum = 0;
        for (int i = 0; i < sz; i++) {
            sum += nums[i];
            if (sum >= s) {
                while (sum >= s) {
                    sum -= nums[back++];
                }
                min_sz = min(min_sz, i - back + 1 + 1);
            }
        }
        
        return min_sz != INT_MAX? min_sz : 0;
    }

int main(int argc, char** argv) {
      int a [] = {1,4,4};
      vector<int> nums(a, a + 3);
      int s = 4;
      cout<<minSubArrayLen(s, nums)<<endl;
      return 0;
}
