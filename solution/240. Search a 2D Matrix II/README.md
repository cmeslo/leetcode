# 240. Search a 2D Matrix II

Time complexity: ```O(m + n)```

從左下角出發

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    int y = m - 1, x = 0;
    while (y >= 0 && x < n) {
        if (matrix[y][x] == target)
            return true;
        else if (matrix[y][x] > target)
            --y;
        else
            ++x;
    }
    return false;
}
```

or

從右上角出發

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    int y = 0, x = n - 1;
    while (y < m && x >= 0) {
        if (matrix[y][x] == target)
            return true;
        else if (matrix[y][x] < target)
            ++y;
        else
            --x;
    }
    return false;
}
```
