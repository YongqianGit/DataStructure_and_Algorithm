#include<iostream>
using namespace std;

int mySqrt(int x) {
        if (x == 0) return 0;
        
        int l = 1, r = x;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (x / m == m) {return m;}
            else if (x / m > m) { // m too small
                l = m + 1;
            }
            else { // m too high
                r = m - 1;
            }
        }
        
        return r;
    }

int main(int argc, char** argv) {
      int x = 11;
      cout<<mySqrt(x) << endl;
      return 0;
}
