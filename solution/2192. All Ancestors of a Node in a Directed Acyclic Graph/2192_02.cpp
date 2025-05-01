class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]);
        
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            dfs(i, i, adj, res);
        }
        return res;
    }
    
private:
    void dfs(int root, int node, vector<vector<int>>& adj, vector<vector<int>>& res) {
        for (int next : adj[node]) {
            if (!res[next].empty() && res[next].back() == root) continue;
            res[next].push_back(root);
            dfs(root, next, adj, res);
        }
    }
};
