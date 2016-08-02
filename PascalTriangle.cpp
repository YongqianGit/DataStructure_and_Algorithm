#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows < 1) return res;
        
        res.push_back(vector<int> (1, 1) );
        
        for (int i = 1; i < numRows; i++ ) {
            vector<int> sol(i + 1, 1);
            for (int j = 1; j <= i / 2; j++) {
                sol[j] = sol[i - j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(sol);
        }
        
        return res;
    }

int main(int argc, char** argv) {
      int n = 4;
      if (argc > 1) {
            n = atoi(argv[1]);
      }
      
      vector<vector<int> > res = generate(n);
      for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                  cout<<res[i][j]<<" ";
            }
            cout<<endl;
      }
      return 0;
}
