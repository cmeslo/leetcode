class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        seen.resize(n);
        
        for (auto& c : connections) {
            int a = c[0], b = c[1];
            adj[a].push_back(b);
            adj[b].push_back(-a);
        }
        
        res = 0;
        dfs(0);
        return res;
    }

private:
    vector<vector<int>> adj;
    vector<int> seen;
    int res;
    
    void dfs(int node) {
        seen[node]++;
        for (int next : adj[node]) {
            int nxt = abs(next);
            if (seen[nxt]) continue;
            if (next > 0) ++res;
            dfs(nxt);
        }
    }
};
