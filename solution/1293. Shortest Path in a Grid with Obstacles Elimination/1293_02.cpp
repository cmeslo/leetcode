class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const vector<int> dirs = {0, -1, 0, 1, 0};
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        
        vector<vector<int>> seen(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        seen[0][0] = 0;
        q.push({0, 0, 0});
        int steps = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int y = q.front()[0], x = q.front()[1], o = q.front()[2];
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ny = y + dirs[d];
                    int nx = x + dirs[d + 1];
                    if (ny == m - 1 && nx == n - 1) return steps + 1;
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                    int no = o + grid[ny][nx];
                    if (seen[ny][nx] <= no || no > k) continue;
                    seen[ny][nx] = no;
                    q.push({ny, nx, no});
                }
            }
            ++steps;
        }
        return -1;
    }
};
