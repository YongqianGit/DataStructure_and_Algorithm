bool canFinish(int numCourses, vector<pair<int, int>>& prereq) {
        vector<int> in_deg(numCourses, 0);
        vector<vector<int> > graph(numCourses, vector<int> () );
        
        for (auto item : prereq) {
            in_deg[item.first]++;
            graph[item.second].push_back(item.first);
        }
        
        stack<int> no_in;
        for (int i = 0; i < numCourses; i++) {
            if (in_deg[i] == 0) {no_in.push(i);}
        }
        
        int cnt = 0;
        while (!no_in.empty() ) {
            int cur = no_in.top();
            no_in.pop();
            cnt++;
            
            for (int item : graph[cur]) {
                if (--in_deg[item] == 0) {no_in.push(item);}
            }
        }
        
        return cnt == numCourses;
    }
