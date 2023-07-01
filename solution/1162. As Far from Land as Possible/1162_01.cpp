class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const vector<int> dirs = {0, 1, 0, -1, 0};
        
        int n = grid.size();
        queue<pair<int, int>> q; // pos, dist
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    q.emplace(i * n + j, 0);
            }
        }

        int res = -1;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                auto [pos, dist] = q.front(); q.pop();
                res = max(res, dist);
                int i = pos / n, j = pos % n;
                for (int k = 0; k < 4; ++k) {
                    int y = i + dirs[k];
                    int x = j + dirs[k + 1];
                    if (y < 0 || y >= n || x < 0 || x >= n || grid[y][x] == 1) continue;
                    grid[y][x] = 1;
                    q.emplace(y * n + x, dist + 1);
                }
            }
        }
        return res == 0 ? -1 : res;
    }
};
