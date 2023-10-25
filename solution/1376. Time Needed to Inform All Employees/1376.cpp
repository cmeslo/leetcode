class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        return dfs(headID, adj, informTime);
    }
    
    int dfs(int node, vector<vector<int>>& adj, vector<int>& informTime) {
        if (node >= adj.size()) return 0;
        int mx = 0;
        for (int next : adj[node]) {
            mx = max(mx, dfs(next, adj, informTime));
        }
        return informTime[node] + mx;
    }
};
