#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// BFS
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        if (n == 1) {return {0};}
        
        vector<vector<int> > graph (n, vector<int> () );
        vector<int> leaf_num (n, 0);
        for (auto item : edges) {
            leaf_num[item.first]++;
            leaf_num[item.second]++;
            
            graph[item.first].push_back(item.second);
            graph[item.second].push_back(item.first);
        }
        
        queue<int> one_leaf;
        for (int i = 0; i < n; i++) {
            if (leaf_num[i] == 1) {one_leaf.push(i); }
        }
        
        while ( n > 2 ) {
            int sz_leaf = one_leaf.size();
            for ( int i = 0; i < sz_leaf; i++ ) { // Cut off the current outmost leaf layer 
                int cur = one_leaf.front();
                one_leaf.pop();
                n--; // cutting off the leaf!!!
                for (int item : graph[cur]) {
                    if (--leaf_num[item] == 1) {
                        one_leaf.push(item);
                    }
                }
            }
        }
        
        vector<int> res;
        while (!one_leaf.empty() ) {
            res.push_back(one_leaf.front() );
            one_leaf.pop();
        }
        
        return res;
    
    }

int main(int argc, char** argv) {
      vector<pair<int, int> > edges = { {1,0}, {1,2}, {1,3} };
      vector<int> res = findMinHeightTrees(n, edges);
      int n = 4;
      for (int i = 0; i < res.size(); i++) {
            cout<<res[i]<<" ";
      }
      cout<<endl;
      return 0;
}
