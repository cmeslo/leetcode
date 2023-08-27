class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int cnt = dfs(grid, i, j);
                    if (cnt != -1)
                        res += cnt;
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size())
            return -1;
        if (g[i][j] == 0)
            return 0;
        
        g[i][j] = 0;
        int d1 = dfs(g, i + 1, j);
        int d2 = dfs(g, i, j + 1);
        int d3 = dfs(g, i - 1, j);
        int d4 = dfs(g, i, j - 1);
        if (d1 == -1 || d2 == -1 || d3 == -1 || d4 == -1)
            return -1;
        return d1 + d2 + d3 + d4 + 1;
    }
};
