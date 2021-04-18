class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1) return -1;
        
        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.emplace(0, 0);
        
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                if (x == n - 1 && y == m - 1) return ans;
                for (int d1 = -1; d1 <= 1; ++d1) {
                    for (int d2 = -1; d2 <= 1; ++d2) {
                        int nx = x + d1, ny = y + d2;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[ny][nx] == 1) continue;
                        grid[ny][nx] = 1;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};
