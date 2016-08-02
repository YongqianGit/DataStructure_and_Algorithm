void gen_IP(string &s, int start, vector<string>& sol, vector<string>& res) {
        if (sol.size() == 4) {
            if (start == s.size() ) {
                string ip = sol[0] + '.' + sol[1] + '.' + sol[2] + '.' + sol[3];
                res.push_back(ip);
            }
            return;
        }
        
        string cur;
        for (int i = start; i < start + 3 && i < s.size(); i++) {
            cur += s[i];
            if (valid(cur) ) {
                sol.push_back(cur);
                gen_IP(s, i + 1, sol, res);
                sol.pop_back();
            }
        }
    }
    
bool valid(string& s) {
        if (s[0] == '0' && s.size() > 1) {return false;}
        int num = stoi(s);
        if (num > 255 ) {return false;}
        
        return true;
    }

vector<string> restoreIpAddresses(string s) {
        vector<string> res, sol;
        gen_IP(s, 0, sol, res);
        return res;
    }
