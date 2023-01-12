class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const vector<int> dirs = {0, 1, 0, -1, 0};
        int res = 0;
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                grid[i][j] = 0;
                q.emplace(i, j);
                int cur = 0;
                while (!q.empty()) {
                    auto [y, x] = q.front(); q.pop();
                    ++cur;
                    for (int k = 0; k < 4; ++k) {
                        int ny = y + dirs[k];
                        int nx = x + dirs[k + 1];
                        if (ny < 0 || ny >= m || nx < 0 || nx >= n || grid[ny][nx] == 0) continue;
                        grid[ny][nx] = 0;
                        q.emplace(ny, nx);
                    }
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
