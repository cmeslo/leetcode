class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += grid[i][j] - '0';
                dfs(grid, i, j);
            }
        }
        return res;
    }
    
private:
    int m, n;
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    void dfs(vector<vector<char>>& grid, int y, int x) {
        if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == '0') return;
        
        grid[y][x] = '0';
        for (int k = 0; k < 4; ++k)
            dfs(grid, y + dirs[k], x + dirs[k + 1]);
    }
    
};
