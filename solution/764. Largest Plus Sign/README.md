# 764. Largest Plus Sign

```cpp
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    vector<vector<int>> up(n, vector<int>(n));
    vector<vector<int>> down(n, vector<int>(n));
    vector<vector<int>> left(n, vector<int>(n));
    vector<vector<int>> right(n, vector<int>(n));

    vector<vector<int>> M(n, vector<int>(n, 1));
    for (auto& m : mines)
        M[m[0]][m[1]] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            up[i][j] = i > 0 && M[i][j] ? up[i - 1][j] + 1 : M[i][j];
            left[i][j] = j > 0 && M[i][j] ? left[i][j - 1] + 1 : M[i][j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            down[i][j] = i < n - 1 && M[i][j] ? down[i + 1][j] + 1 : M[i][j];
            right[i][j] = j < n - 1 && M[i][j] ? right[i][j + 1] + 1 : M[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans = max(ans, min({up[i][j], down[i][j], left[i][j], right[i][j]}));
    return ans;
}
```
