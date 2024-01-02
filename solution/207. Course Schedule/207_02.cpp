class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        adj.resize(n);
        colors.resize(n);
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            adj[a].push_back(b);
        }
        
        for (int i = 0; i < n; ++i)
            if (!dfs(i))
                return false;
        return true;
    }
    
private:
    vector<vector<int>> adj;
    vector<int> colors; // 0: unknow, 1: visiting, 2: visited
    
    bool dfs(int node) {
        if (colors[node] == 1) return false;
        if (colors[node] == 2) return true;
        
        colors[node] = 1;
        for (int next : adj[node]) {
            if (!dfs(next))
                return false;
        }
        colors[node] = 2;
        return true;
    }
};
