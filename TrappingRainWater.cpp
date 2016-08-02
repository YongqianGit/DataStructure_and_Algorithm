#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
        int sz = height.size();
        if (sz < 3) return 0;
        
        vector<int> left_most(sz, 0), right_most(sz, 0);
        
        left_most[0] = height[0];
        right_most.back() = height.back();
        
        for (int i = 1; i < sz; i++) {
            left_most[i] = max(left_most[i-1], height[i]);
            // highest of height[0:i]
        }
        
        int res = 0;
        for (int i = sz - 2; i >= 0; i--) {
            right_most[i] = max(right_most[i+1], height[i]);
            // highest of height[i:end]
            
            int cur = min(right_most[i], left_most[i]);
            res += max(cur - height[i], 0);
        }
        
        return res;
        
    }

int main(int argc, char** argv) {
      int a [] = {1,0,1,3,2,1,2,1};
      vector<int> h (a, a + 8);
      cout<<trap(h)<<endl;
      return 0;
}
