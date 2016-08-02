#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool is_pal(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {return false;}
            l++; r--;
        }
        
        return true;
    }
    
void gen_pal(string s, vector<string> sol, vector<vector<string> >& res) {
        
        if (s.empty() ) {
            res.push_back(sol);
            return;
        }
        
        for (int i = 1; i <= s.size(); i++) { // i is length, NOT position!!
            string cur = s.substr(0, i); // s[0:i-1]
            if (is_pal(cur) ) {
                sol.push_back(cur);
                gen_pal(s.substr(i), sol, res); // s[i:end]
                sol.pop_back();
            }
        }
    }

vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> sol;
        gen_pal(s, sol, res);
        return res;
    }

int main(int argc, char** argv) {
      string s = "aab";
      vector<vector<string> > res = partition(s);
      for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                  cout<<res[i][j]<<" ";
            }
            cout<<endl;
      }
      return 0;
}
