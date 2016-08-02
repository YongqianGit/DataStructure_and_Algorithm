void gen_p (int l, int r, int n, string& sol, vector<string>& res) {
        if ( r == n ) {
            res.push_back(sol);
            return;
        }
        
        if (l < n) {
            sol += '(';
            gen_p(l + 1, r, n, sol, res);
            sol.pop_back();
        }
        
        if (r < l) {
            sol += ')';
            gen_p(l, r + 1, n, sol, res);
            sol.pop_back();
        }
        
    }


vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n < 1) return res;
        string sol;
        gen_p(0, 0, n, sol, res);
        return res;
    }
