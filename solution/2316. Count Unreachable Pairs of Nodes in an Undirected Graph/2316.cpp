class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        colors.resize(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int color = 1;
        for (int i = 0; i < n; ++i) {
            if (!colors[i])
                dfs(i, color++);
        }
        
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i)
            cnt[colors[i]]++;
        
        long long res = 0;
        for (int i = 0; i < n; ++i)
            res += n - cnt[colors[i]];
        return res / 2;
    }
    
private:
    vector<vector<int>> adj;
    vector<int> colors;
    
    void dfs(int node, int color) {
        colors[node] = color;
        for (int next : adj[node]) {
            if (colors[next]) continue;
            dfs(next, color);
        }
    }
};
