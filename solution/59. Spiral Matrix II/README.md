# 59. Spiral Matrix II

## Solution: Simulation

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
