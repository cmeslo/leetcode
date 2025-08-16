class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        // case 1: 原本已經超過一個島, 或沒有島
        int cnt = count(grid);
        if (cnt > 1 || cnt == 0) return 0;
        
        // case 2: 把一個 1 變成 0 後有兩個島, 或沒有島
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int cnt = count(grid);
                    if (cnt > 1 || cnt == 0)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        // case 3: corner
        return 2;
    }
    
private:
    int m, n;
    vector<int> dirs = {0, 1, 0, -1, 0};
    
    int count(vector<vector<int>>& grid) {
        int islands = 0;
        vector<vector<int>> seen(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    queue<pair<int, int>> q;
                    seen[i][j] = 1;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [y, x] = q.front(); q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int ny = y + dirs[k];
                            int nx = x + dirs[k + 1];
                            if (ny < 0 || ny >= m || nx < 0 || nx >= n || grid[ny][nx] == 0 || seen[ny][nx]) continue;
                            seen[ny][nx] = 1;
                            q.push({ny, nx});
                        }
                    }
                    islands++;
                    if (islands > 1) return islands;
                }
            }
        }
        return islands;
    }
};
