vector<int> findOrder(int numCourses, vector<pair<int, int>>& prereq) {
        vector<int> in_deg(numCourses, 0);
        vector<vector<int> > graph(numCourses, vector<int> () );
        
        for (auto item : prereq) {
            in_deg[item.first]++;
            graph[item.second].push_back(item.first);
        }
        
        stack<int> no_in;
        for (int i = 0; i < numCourses; i++) {
            if (in_deg[i] == 0) {no_in.push(i); } 
        }
        
        vector<int> res;
        while (!no_in.empty() ) {
            int cur = no_in.top();
            no_in.pop();
            res.push_back(cur);
            for (int item : graph[cur]) {
                if (--in_deg[item] == 0) {no_in.push(item);}
            }
        }
        
        return res.size() < numCourses? vector<int> () : res;
        
    }
