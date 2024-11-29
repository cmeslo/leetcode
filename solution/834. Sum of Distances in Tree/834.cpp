class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        dp.resize(n);
        cnt.resize(n);
        
        init(0, -1); // init dp[0] only
        dfs(0, -1);
        return dp;
    }
    
private:
    int n;
    vector<vector<int>> adj;
    vector<int> dp;
    vector<int> cnt;
    
    void init(int node, int pre) {
        for (int next : adj[node]) {
            if (next == pre) continue;
            init(next, node);
            cnt[node] += cnt[next];
            dp[node] += dp[next] + cnt[next];
        }
        cnt[node]++;
    }
    
    void dfs(int node, int pre) {
        for (int next : adj[node]) {
            if (pre == next) continue;
            dp[next] = dp[node] + (n - cnt[next]) - cnt[next];
            dfs(next, node);
        }
    }
};
