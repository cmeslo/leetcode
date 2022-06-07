class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int from = e[0], to = e[1];
            adj[to].push_back(from);
        }
        
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            dfs(i, adj, visited, ans[i]);
            ans[i].pop_back();
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
    
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        if (visited[i]) return;
        
        visited[i] = true;
        for (int a : adj[i]) {
            dfs(a, adj, visited, ans);
        }
        ans.push_back(i);
    }
};
