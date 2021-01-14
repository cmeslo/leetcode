# 59. Spiral Matrix II

## Code:

```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, -1));
    int start = 1, end = n * n;
    int y = 0, x = 0;
    int dir = 1; // 1 - right, 2 - down, 3 - left, 4 - up

    while (start <= end) {
        cout << y << ", " << x << endl;
        if (dir == 1) { // go right
            ans[y][x] = start++;
            int next_x = x + 1;
            if (next_x == n || (next_x < n && ans[y][next_x] != -1)) {
                ++y;
                dir = 2;
            } else {
                x = next_x;
            }
        } else if (dir == 2) { // go down
            ans[y][x] = start++;
            int next_y = y + 1;
            if (next_y == n || (next_y < n && ans[next_y][x] != -1)) {
                --x;
                dir = 3;
            } else {
                y = next_y;
            }
        } else if (dir == 3) { // go left
            ans[y][x] = start++;
            int next_x = x - 1;
            if (next_x < 0 || ans[y][next_x] != -1) {
                --y;
                dir = 4;
            } else {
                x = next_x;
            }
        } else if (dir == 4) { // go up
            ans[y][x] = start++;
            int next_y = y - 1;
            if (next_y < 0 || ans[next_y][x] != -1) {
                ++x;
                dir = 1;
            } else {
                y = next_y;
            }
        }
    }
    return ans;
}
```

更簡潔：

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
