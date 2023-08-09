class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        seen.resize(n);
        
        for (auto& c : connections) {
            int a = c[0], b = c[1];
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }
        
        res = 0;
        dfs(0);
        return res;
    }

private:
    vector<vector<pair<int, int>>> adj; // {node, direction}
    vector<int> seen;
    int res;
    
    void dfs(int node) {
        seen[node]++;
        for (auto [next, dir] : adj[node]) {
            if (seen[next]) continue;
            if (dir) ++res;
            dfs(next);
        }
    }
};
