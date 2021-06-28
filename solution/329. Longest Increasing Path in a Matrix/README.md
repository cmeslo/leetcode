# 329. Longest Increasing Path in a Matrix

## Solution: DFS + memorization

```cpp
// Your runtime beats 91.94 % of cpp submissions.
// Your memory usage beats 44.57 % of cpp submissions.

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> mem(m, vector<int>(n));
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x)
                ans = max(ans, dfs(matrix, y, x, mem));
        return ans;
    }
    
private:
    const vector<int> dirs = {0, -1, 0, 1, 0};
    
    int dfs(vector<vector<int>>& matrix, int y, int x, vector<vector<int>>& mem) {
        int m = matrix.size(), n = matrix[0].size();
        if (mem[y][x]) return mem[y][x];
        
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i];
            int nx = x + dirs[i + 1];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (matrix[y][x] >= matrix[ny][nx]) continue;
            ans = max(ans, dfs(matrix, ny, nx, mem));
        }
        return mem[y][x] = 1 + ans;
    }
};
```
