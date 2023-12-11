class Solution {
public:
    
    int shortestPathAllKeys(vector<string>& grid) {
        const vector<int> dirs = {0, -1, 0, 1, 0};
        const int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> q; // position, status
        int seen[31][31][1 << 6];
        memset(seen, 0, sizeof(seen));
        
        int keyCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '.') continue;
                if (grid[i][j] == '@') {
                    seen[i][j][0] = 1;
                    q.push({i * n + j, 0});
                } else if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    ++keyCount;
                }
            }
        }
        int finalStatus = (1 << keyCount) - 1;
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [pos, status] = q.front(); q.pop();
                if (status == finalStatus) return steps;
                int i = pos / n, j = pos % n;
                for (int k = 0; k < 4; ++k) {
                    int y = i + dirs[k];
                    int x = j + dirs[k + 1];
                    if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == '#') continue;
                    if ('A' <= grid[i][j] && grid[i][j] <= 'F') {
                        if (!((status >> (grid[i][j] - 'A')) & 1))
                            continue;
                    }
                    int newPos = y * n + x;
                    int newStatus = status;
                    if ('a' <= grid[y][x] && grid[y][x] <= 'f') {
                        newStatus |= (1 << (grid[y][x] - 'a'));
                    }
                    if (!seen[y][x][newStatus]) {
                        seen[y][x][newStatus] = 1;
                        q.push({newPos, newStatus});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
