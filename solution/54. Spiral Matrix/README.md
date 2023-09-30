# 54. Spiral Matrix

## Solution 1

在 for 循環裡判斷 ```res.size() < size``` 是避免最後讀到最中間時重覆 push_back。

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int up = 0, down = m - 1;
    int left = 0, right = n - 1;
    int size = m * n;

    vector<int> res;
    while (res.size() < size) {
        for (int j = left; j <= right && res.size() < size; ++j)
            res.push_back(matrix[up][j]);

        for (int i = up + 1; i <= down - 1 && res.size() < size; ++i)
            res.push_back(matrix[i][right]);

        for (int j = right; j >= left && res.size() < size; --j)
            res.push_back(matrix[down][j]);

        for (int i = down - 1; i >= up + 1 && res.size() < size; --i)
            res.push_back(matrix[i][left]);

        up++; right--; down--; left++;
    }
    return res;
}
```

## Solution 2: ```dy,dx = dx,-dy```

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int y = 0, x = 0;
        int dy = 0, dx = 1; // direction
        int next_y, next_x;
        for (int i = 0; i < m * n; ++i) {
            res[i] = matrix[y][x];
            matrix[y][x] = -101;
            next_y = y + dy, next_x = x + dx;
            if (next_y < 0 || next_y >= m || next_x < 0 || next_x >= n || matrix[next_y][next_x] == -101) {
                swap(dy, dx);
                dx = -dx;
            }
            y += dy, x += dx;
        }
        return res;
    }
};

// 0,0 -> 0,1 -> 0,2 -> 1,2 -> 2,2 -> 2,1 -> 2,0 -> 1,0 -> 1,1

// 0,1 ---------------> 1,0 -> 0,-1 ------> -1,0 -> 0,1 -> 

// dy,dx = dx,-dy
```
