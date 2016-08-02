#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int> (n, -1) );
        
        int l = 0, r = n - 1, t = 0, b = n - 1;
        int cnt = 1;
        while (l <= r) {
            for (int i = l; i <= r; i++) { // top 
                res[t][i] = cnt++;
            }
            t++;
            
            for (int i = t; i <= b; i++) { // right
                res[i][r] = cnt++;
            }
            r--;
            
            for (int i = r; i >= l; i--) { // bottom
                res[b][i] = cnt++;
            }
            b--;
            
            for (int i = b; i >= t; i--) { // left
                res[i][l] = cnt++;
            }
            l++;
        }
        
        return res;
    }

int main(int argc, char** argv) {
      int n = 4;
      vector<vector<int> > res = generateMatrix(n);
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  cout<<res[i][j]<<" ";
            }
            cout<<endl;
      }
      return 0;
}
