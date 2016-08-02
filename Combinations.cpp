void gen_comb(int n, int k, int start, vector<int>& sol, vector<vector<int> >& res) {
        if (sol.size() == k) {
            res.push_back(sol);
            return;
        }
        
        for (int i = start; i <= n; i++) {
            sol.push_back(i);
            gen_comb(n, k, i + 1, sol, res);
            sol.pop_back();
        }
    }

vector<vector<int>> combine(int n, int k) {
        vector<int> sol;
        vector<vector<int> > res;
        gen_comb(n, k, 1, sol, res);
        return res;
    }
