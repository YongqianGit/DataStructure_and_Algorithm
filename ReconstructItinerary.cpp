void gen_itin(unordered_map<string, multiset<string> >& graph, string cur, \
    vector<string>& res) {
        while (!graph[cur].empty() ) {
            string next = *(graph[cur].begin() );
            graph[cur].erase(graph[cur].begin() );
            gen_itin(graph, next, res);
        }
        
        res.push_back(cur);
    }

 vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string> > graph;
        for (auto item : tickets) {
            graph[item.first].insert(item.second);
        }
        
        vector<string> res;
        gen_itin(graph, "JFK", res);
        reverse(res.begin(), res.end() );
        return res;
    }
