class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]);
        
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            vector<bool> seen(n);
            seen[i] = true;
            dfs(i, i, adj, seen, res);
        }
        return res;
    }
    
private:
    void dfs(int root, int node, vector<vector<int>>& adj, vector<bool>& seen, vector<vector<int>>& res) {
        for (int next : adj[node]) {
            if (seen[next]) continue;
            seen[next] = true;
            res[next].push_back(root);
            dfs(root, next, adj, seen, res);
        }
    }
};
