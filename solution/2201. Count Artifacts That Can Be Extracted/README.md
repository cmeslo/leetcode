# 2201. Count Artifacts That Can Be Extracted

## Solution: Simulation

```cpp
int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
    vector<vector<int>> M(1001, vector<int>(1001, -1));
    unordered_map<int, int> m;
    for (int i = 0; i < artifacts.size(); ++i) {
        auto& a = artifacts[i];
        int y1 = a[0], x1 = a[1], y2 = a[2], x2 = a[3];
        int len = 0;
        for (int y = y1; y <= y2; ++y) {
            for (int x = x1; x <= x2; ++x) {
                M[y][x] = i;
                len++;
            }
        }
        m[i] = len;
    }

    int ans = 0;
    unordered_map<int, int> count;
    for (auto& d : dig) {
        int y = d[0], x = d[1];
        int color = M[y][x];
        if (++count[color] == m[color])
            ans++;
    }
    return ans;
}
```
