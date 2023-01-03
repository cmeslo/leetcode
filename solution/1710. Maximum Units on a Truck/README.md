# 1710. Maximum Units on a Truck

```cpp
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(begin(boxTypes), end(boxTypes), [&](auto& a, auto& b) {
        return a[1] > b[1];
    });

    int ans = 0;
    for (int i = 0; i < boxTypes.size() && truckSize >= 0; ++i) {
        ans += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
        truckSize -= boxTypes[i][0];
    }
    return ans;
}
```

or

```cpp
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](auto & a, auto& b) {
        return a[1] > b[1];
    });

    int ans = 0;
    for (auto& box : boxTypes) {
        int cnt = min(box[0], truckSize), cost = box[1];
        ans += cnt * cost;
        truckSize -= cnt;
        if (truckSize == 0) break;
    }
    return ans;
}
```
