class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        int m = matrix.size(), n = matrix[0].size();
        const vector<int> dirs = {0, -1, 0, 1, 0};
        vector<vector<int>> visited(m, vector<int>(n)); // 1: Pacific visited, 2: Atlantic visited
        
        // Pacific BFS
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            visited[i][0] = 1;
            q.emplace(i, 0);
        }
        for (int j = 1; j < n; ++j) {
            visited[0][j] = 1;
            q.emplace(0, j);
        }
        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[ny][nx] == 1) continue;
                if (matrix[y][x] > matrix[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.emplace(ny, nx);
            }
        }
        
        // Atlantic BFS
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            if (visited[i][n - 1] == 1)
                ans.push_back({i, n - 1});
            visited[i][n - 1] = 2;
            q.emplace(i, n - 1);
        }
        for (int j = 0; j < n - 1; ++j) {
            if (visited[m - 1][j] == 1)
                ans.push_back({m - 1, j});
            visited[m - 1][j] = 2;
            q.emplace(m - 1, j);
        }
        while (!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[ny][nx] == 2) continue;
                if (matrix[y][x] > matrix[ny][nx]) continue;
                if (visited[ny][nx] == 1) ans.push_back({ny, nx});
                visited[ny][nx] = 2;
                q.emplace(ny, nx);
            }
        }
        return ans;
    }
};
