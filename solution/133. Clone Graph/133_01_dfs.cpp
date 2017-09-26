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
        unordered_map<int, UndirectedGraphNode*> m;
        return cloneGraph(node, m);
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& m) {
        if (node == NULL) return NULL;
        if (m.count(node->label)) return m[node->label];
        
        UndirectedGraphNode *dup = new UndirectedGraphNode(node->label);
        m[node->label] = dup;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            dup->neighbors.push_back(cloneGraph(node->neighbors[i], m));
        }
        return dup;
    }
};
