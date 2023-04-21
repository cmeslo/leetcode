class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const vector<int> dirs = {0, -1, 0, 1, 0};
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        
        vector<vector<int>> seen(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        seen[0][0] = k;
        q.emplace(0, k);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [pos, power] = q.front();
                q.pop();
                int y = pos / n, x = pos % n;
                for (int i = 0; i < 4; ++i) {
                    int ny = y + dirs[i];
                    int nx = x + dirs[i + 1];
                    int npos = ny * n + nx;
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                    int npower = power - (grid[ny][nx] == 1);
                    if (npower < 0 || seen[ny][nx] >= npower) continue;
                    seen[ny][nx] = npower;
                    if (ny == m - 1 && nx == n - 1) return step + 1;
                    q.emplace(npos, npower);
                }
            }
            step++;
        }
        return -1;
    }
};
