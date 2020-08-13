# 994. Rotting Oranges

## 版本一

```cpp
// Your runtime beats 94.16 % of cpp submissions.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        int ans = 0;
        
        queue<pair<int, int>> q;
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (grid[y][x] == 2) {
                    grid[y][x] = 0;
                    q.push({y, x});
                }
        
        while (!q.empty()) {
            int size = q.size();
            ans++;
            while (size--) {
                auto cur = q.front(); q.pop();
                for (const auto& dir : dirs) {
                    int next_y = cur.first + dir[0], next_x = cur.second + dir[1];
                    if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w && grid[next_y][next_x] == 1) {
                        grid[next_y][next_x] = 0;
                        q.push({next_y, next_x});
                    }
                }      
            }
        }
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (grid[y][x] == 1) return -1;
        
        return ans == 0 ? 0 : ans - 1;
    }

private:
    const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
```

## 版本二，省卻最後一次循環

```cpp
// Your runtime beats 99.44 % of cpp submissions

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        int mins = 0, fresh = 0;
        
        queue<pair<int, int>> q;
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 2) q.push({y, x});
                else if (grid[y][x] == 1) ++fresh;
            }
        
        // 添加 fresh 橙判斷: 因為最後一批感染的壞橙、也會放到 queue 裡，但這時已經完成操作，答案不用加一
        while (!q.empty() && fresh) {
            int size = q.size();
            mins++;
            while (size--) {
                auto cur = q.front(); q.pop();
                for (const auto& dir : dirs) {
                    int next_y = cur.first + dir[0], next_x = cur.second + dir[1];
                    if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w && grid[next_y][next_x] == 1) {
                        grid[next_y][next_x] = 2;
                        q.push({next_y, next_x});
                        --fresh;
                    }
                }      
            }
        }
        
        return fresh ? -1 : mins;
    }

private:
    const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
```
