# 2136. Earliest Possible Day of Full Bloom

生長時間越長的，越優先處理。

```cpp
int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<int> A(n);
    for (int i = 0; i < n; ++i) A[i] = i;

    sort(begin(A), end(A), [&](int i, int j) {
        return growTime[i] > growTime[j];
    });

    int ans = 0;
    int plantTotal = 0;
    for (int i : A) {
        plantTotal += plantTime[i];
        ans = max(ans, plantTotal + growTime[i]);
    }
    return ans;
}
```

or

```cpp
int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        A[i] = {growTime[i], plantTime[i]};
    }
    sort(A.rbegin(), A.rend());

    int base = 0, mx = 0;
    for (auto [g, p] : A) {
        base = base + p;
        mx = max({mx, base + g});
    }
    return mx;
}
```
