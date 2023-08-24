class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0)
                fillOne(grid, i, 0);
            if (grid[i][n - 1] == 0)
                fillOne(grid, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 0)
                fillOne(grid, 0, j);
            if (grid[m - 1][j] == 0)
                fillOne(grid, m - 1, j);
        }
        
        int res = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    res++;
                    fillOne(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    void fillOne(vector<vector<int>>& grid, int startY, int startX) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        grid[startY][startX] = 1;
        q.emplace(startY, startX);
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int y = i + dirs[k];
                int x = j + dirs[k + 1];
                if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == 1) continue;
                grid[y][x] = 1;
                q.emplace(y, x);
            }
        }
    }
};
