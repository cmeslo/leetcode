class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        safe.resize(n, -1); // -1: unknow, 0: unsafe, 1: safe
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (dfs(graph, i))
                res.push_back(i);
        }
        return res;
    }
    
private:
    vector<int> safe;
    
    bool dfs(vector<vector<int>>& graph, int node) {
        if (safe[node] != -1) return safe[node];
        
        safe[node] = false;
        for (int next : graph[node]) {
            if (!dfs(graph, next))
                return false;
        }
        return safe[node] = true;
    }
};
