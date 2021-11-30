# 2078. Two Furthest Houses With Different Colors

## Solution

如果存在不同顏色的房子，最遠的距離（答案）會在第一間房子、或者最後一間房子。

```cpp
int maxDistance(vector<int>& colors) {
    int res = 0;
    int n = colors.size();
    for (int i = 0; i < n; ++i) {
        if (colors[i] != colors[0]) // 與第一間房子不同顏色的
            res = max(res, i);
        if (colors[i] != colors[n - 1]) // 與最後一間房子不同顏色的
            res = max(res, n - 1 - i);
    }
    return res;
}
```
