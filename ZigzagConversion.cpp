#include<iostream>
#include<string>
using namespace std;

string convert(string s, int numRows) {
        if (s.empty() || numRows == 1) return s;
        
        int sz = s.size(), gap = numRows * 2 - 2;
        
        string res;
        
            
        for (int i = 0; i < numRows; i++) {
            
            int id = i ;
            while (id < sz) {
                
                res += s[id];
                
                if (i > 0 && i < numRows - 1) {
                    int id2 = id + gap - 2 * i;
                    if (id2 < sz) res += s[id2];
                }
                id += gap;
            }
        }
        
        return res;
    
    }

int main(int argc, char** argv) {
      string s = "123456789";
      int row = 3;
      cout<<convert(s, row)<<endl;
      return 0;
}
