# 59. Spiral Matrix II

## Solution: Simulation

### 寫法一

```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;
    int num = 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int i = colStart; i <= colEnd; ++i)
            ans[rowStart][i] = num++;
        ++rowStart;

        for (int i = rowStart; i <= rowEnd; ++i)
            ans[i][colEnd] = num++;
        --colEnd;

        for (int i = colEnd; i >= colStart; --i)
            ans[rowEnd][i] = num++;
        --rowEnd;

        for (int i = rowEnd; i >= rowStart; --i)
            ans[i][colStart] = num++;
        ++colStart;
    }

    return ans;
}
```

or

```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int r1 = 0, r2 = n - 1;
    int c1 = 0, c2 = n - 1;
    int i = 1, size = n * n;
    while (i <= size) {
        for (int x = c1; x <= c2; ++x)
            ans[r1][x] = i++;

        for (int y = r1 + 1; y < r2 && i <= size; ++y)
            ans[y][c2] = i++;

        for (int x = c2; x >= c1 && i <= size; --x)
            ans[r2][x] = i++;

        for (int y = r2 - 1; y > r1 && i <= size; --y)
            ans[y][c1] = i++;

        r1++, r2--;
        c1++, c2--;
    }
    return ans;
}
```

### 寫法二（推薦）

```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0;
    int y = 0, x = -1;
    for (int i = 1; i <= n * n; ++i) {
        int next_y = y + dirs[d][0];
        int next_x = x + dirs[d][1];
        // 因為下一步會走出邊界、或者已經走過，所以要轉方向
        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n|| ans[next_y][next_x] != 0)
            d = (d + 1) % 4;
        y = y + dirs[d][0];
        x = x + dirs[d][1];
        ans[y][x] = i;
    }
    return ans;
}
```

### 寫法三: ```dy, dx = dx, -dy```

```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int y = 0, x = 0;
    int dy = 0, dx = 1;
    for (int i = 1; i <= n * n; ++i) {
        ans[y][x] = i;
        int ny = y + dy;
        int nx = x + dx;
        // 因為下一步會走出邊界、或者已經走過，所以要轉方向
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || ans[ny][nx] != 0) {
            swap(dy, dx);
            dx = -dx;
        }
        y += dy, x += dx;
    }
    return ans;
}
```
