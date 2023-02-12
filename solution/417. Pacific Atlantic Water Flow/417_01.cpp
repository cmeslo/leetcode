class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        mark.resize(m, vector<int>(n));
        
        for (int j = 0; j < n; ++j) {
            bfs(heights, 0, j, 0); // Pacific Ocean
            bfs(heights, m - 1, j, 1); // Atlantic Ocean
        }
        for (int i = 0; i < m; ++i) {
            bfs(heights, i, 0, 0); // Pacific Ocean
            bfs(heights, i, n - 1, 1); // Atlantic Ocean
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mark[i][j] == 3)
                    res.push_back({i, j});
            }
        }
        return res;
    }
    
private:
    int m, n;
    vector<vector<int>> mark;
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    void bfs(vector<vector<int>>& H, int i, int j, int flag) {
        if (mark[i][j] & (1 << flag)) return;
        
        queue<pair<int, int>> q;
        mark[i][j] |= (1 << flag);
        q.emplace(i, j);
        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int ny = y + dirs[k];
                int nx = x + dirs[k + 1];
                if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                if (H[y][x] > H[ny][nx]) continue;
                if (mark[ny][nx] & (1 << flag)) continue;
                mark[ny][nx] |= (1 << flag);
                q.emplace(ny, nx);
            }
        }
    }
};
