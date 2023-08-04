class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> color(n + 1);
        vector<vector<int>> adj(n + 1);
        for (auto& r : roads) {
            int a = r[0], b = r[1], d = r[2];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(adj, 1, color, 1);
        
        int res = INT_MAX;
        for (auto& r : roads) {
            if (color[r[0]] == 1)
                res = min(res, r[2]);
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& adj, int node, vector<int>& color, int red) {
        color[node] = red;
        for (int next : adj[node]) {
            if (color[next] == red) continue;
            dfs(adj, next, color, red);
        }
    }
};
