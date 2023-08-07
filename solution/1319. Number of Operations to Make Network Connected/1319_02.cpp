class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        adj.resize(n);
        seen.resize(n);
        
        for (auto& c : connections) {
            int a = c[0], b = c[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int network = 0;
        for (int i = 0; i < n; ++i)
            network += dfs(i);
        return network - 1;
    }
    
private:
    vector<vector<int>> adj;
    vector<int> seen;
    
    int dfs(int node) {
        if (seen[node]++) return 0;
        for (int next : adj[node])
            dfs(next);
        return 1;
    }
};
