# 554. Brick Wall

## Solution: Prefix sum

Using a map to store seams

The more seam you cut, the less brick you cross.

```cpp
int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> edges;
    auto mn = wall.size(); // size_t

    for (auto& row : wall) {
        for (int i = 0, width = 0; i < row.size() - 1; ++i) {
            width += row[i];
            edges[width]++;
            mn = min(mn, wall.size() - edges[width]);
        }
    }
    return mn;
}
```
