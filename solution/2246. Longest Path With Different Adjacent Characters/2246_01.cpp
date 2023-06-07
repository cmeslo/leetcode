class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> adj2(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
            if (s[i] != s[parent[i]])
                adj2[parent[i]].push_back(i);
        }
        
        vector<int> dp(n);
        dp[0] = dfs(adj, s, 0, dp);
        
        for (int i = 0; i < n; ++i) {
            sort(adj2[i].begin(), adj2[i].end(), [&](int a, int b) {
                return dp[a] > dp[b];
            });
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 1;
            for (int j = 0; j < 2 && j < adj2[i].size(); ++j) {
                sum += dp[adj2[i][j]];
            }
            ans = max(ans, sum);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& adj, string& s, int node, vector<int>& dp) {
        dp[node] = 1;
        for (int next : adj[node]) {
            if (s[node] == s[next])
                dfs(adj, s, next, dp);
            else
                dp[node] = max(dp[node], 1 + dfs(adj, s, next, dp));
        }
        return dp[node];
    }
};
