# 542. 01 Matrix

## Solution 1: BFS

```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> res(m, vector<int>(n, INT_MAX));

    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                res[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    const vector<int> dirs = {0, -1, 0, 1, 0};
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int y = i + dirs[k];
            int x = j + dirs[k + 1];
            if (y < 0 || y >= m || x < 0 || x >= n || res[y][x] != INT_MAX) continue;
            res[y][x] = res[i][j] + 1;
            q.emplace(y, x);
        }
    }
    return res;
}
```
