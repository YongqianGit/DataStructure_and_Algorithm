#include<iostream>
#include<vector>

using namespace std;

void gen_comb(int k, int target, int start, vector<int>& sol, vector<vector<int> >& res) {
        if (target < 0) {return;}
        if (sol.size() == k) {
            if (target == 0) {
                res.push_back(sol);
            }
            return;
        }
        
        for (int i = start; i < 10; i++) {
            sol.push_back(i);
            gen_comb(k, target - i, i + 1, sol, res);
            sol.pop_back();
        }
    }

vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        if (k < 1) return res;
        vector<int> sol;
        gen_comb(k, n, 1, sol, res);
        return res;
    }

int main(int argc, char** argv) {
      int k = 3, n = 7;
      vector<vector<int> > res = combinationSum3(k, n);
      for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                  cout<< res[i][j]<<" ";
            }
            cout<<endl;
      }
      return 0;
}
