#include<iostream>
#include<string>
using namespace std;

int titleToNumber(string s) {
        int res = 0;
        int sz = s.size();
        
        for (int i = 0; i < sz; i++) {
            res = res * 26 + s[i] - 'A' + 1;
        }
        
        return res;
    }

int main(int argc, char** argv) {
      string s = "AZ";
      cout<<titleToNumber(s)<<endl;
      return 0;
}
