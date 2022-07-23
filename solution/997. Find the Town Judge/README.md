# 997. Find the Town Judge

```cpp
// Runtime: 239 ms, Your runtime beats 66.29 % of cpp submissions.
// Memory Usage: 60.9 MB, Your memory usage beats 67.54 % of cpp submissions.

int findJudge(int n, vector<vector<int>>& trust) {
    vector<pair<int, int>> A(n + 1);
    for (auto& t : trust) {
        A[t[0]].first++;
        A[t[1]].second++;
    }
    for (int i = 1; i <= n; ++i) {
        auto& [trust, reliability] = A[i];
        if (trust == 0 && reliability == n - 1)
            return i;
    }
    return -1;
}
```

or

```cpp
// Runtime: 148 ms, Your runtime beats 99.98 % of cpp submissions.
// Memory Usage: 60.7 MB, Your memory usage beats 94.55 % of cpp submissions.

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> count(n + 1);
    for (auto& t : trust) {
        count[t[0]]--;
        count[t[1]]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (count[i] == n - 1)
            return i;
    }
    return -1;
}
```
