#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

string simplifyPath(string path) {
        if (path.empty() ) return "";
        vector<string> loc;
        istringstream str_in (path);
        string cur;
        while (getline(str_in, cur, '/') ) {
            if (cur == "" || cur == ".") {continue;}
            else if (cur == "..") {
                if ( !loc.empty() ) {loc.pop_back();}
            }
            else {
                loc.push_back(cur);
            }
        }
        
        string res;
        
        for (string item : loc) {
            res += '/' + item;
        }
        
        return res.empty()? "/" : res;
        
    }

int main(int argc, char** argv) {
      string p = "/a/./b/../../c/";
      cout<<simplifyPath(p) <<endl;
      return 0;
}
