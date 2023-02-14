# 417. Pacific Atlantic Water Flow

## Solution 1 - BFS

第一次遍歷，標記pacific，

第二次遍歷，標記atlantic，同時如果碰到pacific的標記，那就是其中一個答案。

```cpp
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
```

or

簡潔一點的寫法：

```cpp
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
```

## Solution 2 - DFS

```cpp
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        m = matrix.size(), n = matrix[0].size();
        colors.resize(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i)
            dfs(matrix, i, 0, 1);
        for (int j = 0; j < n; ++j)
            dfs(matrix, 0, j, 1);
        for (int i = 0; i < m; ++i)
            dfs(matrix, i, n - 1, -1);
        for (int j = 0; j < n; ++j)
            dfs(matrix, m - 1, j, -1);
            
        return ans;
    }
    
private:
    int m, n;
    const vector<int> dirs {0, -1, 0, 1, 0};
    vector<vector<int>> colors; // 0: unknow, 1: red, -1: blue
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& matrix, int y, int x, int color) {
        if (colors[y][x] == color) return;
        if (colors[y][x] == - color) ans.push_back({y, x});
        
        colors[y][x] = color;
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i];
            int nx = x + dirs[i + 1];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (matrix[y][x] > matrix[ny][nx]) continue;
            dfs(matrix, ny, nx, color);
        }
    }
};
```
