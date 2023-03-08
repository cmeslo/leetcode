# 2007. Find Original Array From Doubled Array

## Solution: Hashmap

```cpp
vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    if (n % 2) return {};

    unordered_map<int, int> m;
    for (int x : changed)
        m[x]++;

    vector<int> res;
    sort(changed.begin(), changed.end());
    for (int x : changed) {
        int target = x + x;
        if (!m.count(x)) continue;
        if (--m[x] == 0) m.erase(x);

        if (!m.count(target)) break;
        if (--m[target] == 0) m.erase(target);

        res.push_back(x);
        if (res.size() == n / 2) return res;
    }
    return {};
}
```
