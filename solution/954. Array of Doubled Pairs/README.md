# 954. Array of Doubled Pairs

```cpp
bool canReorderDoubled(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), [&](int a, int b) {
        if (a < 0 && b < 0)
            return a > b;
        return a < b;
    });

    unordered_map<int, int> m;
    for (int x : arr) ++m[x];
    if (m[0] % 2) return false;
    m.erase(0);

    for (int x : arr) {
        if (m[x] == 0) continue;
        if (m.count(x * 2)) {
            int mn = min(m[x], m[x * 2]);
            m[x] -= mn;
            m[x * 2] -= mn;
        }
    }
    for (int x : arr)
        if (m[x] != 0)
            return false;
    return true;
}
```
