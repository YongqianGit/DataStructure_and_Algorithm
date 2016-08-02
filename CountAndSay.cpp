#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n) {
        string res = "1";
        if (n == 1) return res;
        
        for (int i = 1; i < n; i++) {
            int cnt = 1;
            string cur = "";
            for (int j = 1; j < res.size(); j++) {
                if (res[j-1] == res[j]) {cnt++;}
                else {
                    cur += to_string(cnt) + res[j-1];
                    cnt = 1;
                }
            }
            cur += to_string(cnt) + res.back();
            res = cur;
        }
        
        return res;
    }


int main(int argc, char** argv) {
      int n = 2;
      cout<<countAndSay(n)<<endl;
      return 0;
}
