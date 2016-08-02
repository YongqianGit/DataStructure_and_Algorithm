#include<iostream>
#include<vector>
#include<string>
using namespace std;

string getPermutation(int n, int k) {
        vector<int> factor(n, 1);
        vector<char> digits(n, '1');
        
        for (int i = 1; i < n; i++) {
            digits[i] += i;
            factor[i] = factor[i-1] * i;
        }
        
        string res;
        k--;

        for (int i = n - 1; i >= 0; i--) {
            int id = k / factor[i]; 
            res += digits[id];
            digits.erase(digits.begin() + id); // IMPORTANT!!!
            k %= factor[i];
        }
        
        return res;
        
    }

int main(int argc, char** argv) {
      int n = 4, k = 1;
      cout<<getPermutation(n, k)<<endl;
      return 0;
}
