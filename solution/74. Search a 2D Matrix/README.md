# 74. Search a 2D Matrix

## Solution: binary search

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;

    int h = matrix.size();
    int w = matrix[0].size();
    int l = 0, r = h * w;

    while (l < r) {
        int mid = l + (r - l) / 2;
        int val = matrix[mid / w][mid % w];
        if (val == target) return true;
        if (val < target)
            l = mid + 1;
        else
            r = mid;
    }

    return false;
}
```

or

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m * n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int y = mid / n;
        int x = mid % n;
        if (matrix[y][x] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left < m * n && matrix[left / n][left % n] == target;
}
```
