class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = (1L * res + dfs(grid, 0, i, j)) % M;
            }
        }
        return res;
    }
    
private:
    const int M = 1e9 + 7;
    int memo[1001][1001];
    int m, n;
    
    int dfs(vector<vector<int>>& grid, int pre, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (pre >= grid[i][j]) return 0;
        
        if (memo[i][j]) return memo[i][j];
        
        long cnt = 1L * dfs(grid, grid[i][j], i + 1, j)
                   + dfs(grid, grid[i][j], i - 1, j)
                   + dfs(grid, grid[i][j], i, j + 1)
                   + dfs(grid, grid[i][j], i, j - 1)
                   + 1;
        return memo[i][j] = cnt % M;
    }
};
