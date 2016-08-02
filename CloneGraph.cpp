/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> clone_map;
        UndirectedGraphNode* new_node = new UndirectedGraphNode (node->label);
        clone_map[node] = new_node;
        queue<UndirectedGraphNode*> org_nd;
        org_nd.push(node);
        
        while (!org_nd.empty() ) {
            UndirectedGraphNode* org_cur = org_nd.front();
            org_nd.pop();
            
            for (auto item : org_cur->neighbors) {
                if (clone_map.find(item) == clone_map.end() ) {// NOT created yet
                    org_nd.push(item);
                    UndirectedGraphNode* cur_cl = new UndirectedGraphNode (item->label);
                    clone_map[item] = cur_cl;
                }
                
                clone_map[org_cur]->neighbors.push_back( clone_map[item] );
            }
        }
        
        return new_node;
    }
};
