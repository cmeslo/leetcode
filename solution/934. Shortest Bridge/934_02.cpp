class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }
        int steps = 0;
        const vector<int> dirs = {0, -1, 0, 1, 0};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int y = i + dirs[k];
                    int x = j + dirs[k + 1];
                    if (y < 0 || y >= n || x < 0 || x >= n || grid[y][x] == 2) continue;
                    if (grid[y][x] == 1) return steps;
                    grid[y][x] = 2;
                    q.emplace(y, x);
                }
            }
            ++steps;
        }
        return -1;
    }

    void dfs(vector<vector<int>>& g, int i, int j, queue<pair<int, int>>& q) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] != 1) return;
        g[i][j] = 2;
        q.emplace(i, j);
        dfs(g, i + 1, j, q);
        dfs(g, i - 1, j, q);
        dfs(g, i, j + 1, q);
        dfs(g, i, j - 1, q);
    }
};
