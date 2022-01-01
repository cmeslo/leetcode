# 73. Set Matrix Zeroes

## Solution 1: 使用 O(m + n) 空間的方法

```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> mark(m + n, false);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] == 0)
                mark[j] = mark[i + n] = true;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (mark[j] || mark[i + n])
                matrix[i][j] = 0;
}
```

## Solution 2: 按題目要求，不使用額外空間的方法

```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool isZeroCol = false; // 用兩個變量單獨處理第一、第二行，
    bool isZeroRow = false; // 再把第一行和第一列作為其他行列的標記

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                if (i == 0) isZeroRow = true;
                if (j == 0) isZeroCol = true;
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (isZeroCol) {
        for (int i = 0; i < m; ++i)
            matrix[i][0] = 0;
    }
    if (isZeroRow) {
        for (int j = 0; j < n; ++j)
            matrix[0][j] = 0;
    }
}
```
