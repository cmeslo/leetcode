class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        safe.resize(n, -1);
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            vector<int> seen(n);
            if (dfs(graph, i, seen))
                res.push_back(i);
        }
        return res;
    }
    
private:
    vector<int> safe;
    
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& seen) {
        if (graph[node].empty()) return safe[node] = true;
        if (safe[node] != -1) return safe[node];
        
        seen[node] = true;
        for (int next : graph[node]) {
            if (safe[next] == true) continue;
            if (seen[next] || !dfs(graph, next, seen))
                return safe[node] = false;
        }
        return safe[node] = true;
    }
};
