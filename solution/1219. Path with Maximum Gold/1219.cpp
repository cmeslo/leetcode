class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }

private:
    const vector<int> dirs = {0, -1, 0, 1, 0};
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
        int val = grid[i][j];
        grid[i][j] = 0;
        int mx = 0;
        for (int k = 0; k < 4; ++k) {
            int y = i + dirs[k];
            int x = j + dirs[k + 1];
            mx = max(mx, dfs(grid, y, x));
        }
        grid[i][j] = val;
        return mx + val;
    }
};
