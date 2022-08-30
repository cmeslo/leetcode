# 1288. Remove Covered Intervals

sort

## 1288_01.cpp

```cpp
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return (a[0] < b[0]) || (a[0] == b[0] && b[1] < a[1]);
    });

    int covered = 0;
    int start = 0, end = 0;
    for (const auto& interval : intervals) {
        if (start <= interval[0] && interval[1] <= end)
            ++covered;
        else
            start = interval[0], end = interval[1];
    }

    return intervals.size() - covered;
}
```

## 1288_02.cpp

```cpp
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return (a[0] < b[0]) || (a[0] == b[0] && b[1] < a[1]);
    });

    int ans = 0, end = 0;
    for (const auto& interval : intervals) {
        if (end < interval[1]) {
            ++ans;
            end = interval[1];
        }
    }

    return ans;
}
```

or

```cpp
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int ans = 0, left = -1, right = -1;
    sort(intervals.begin(), intervals.end());
    for (auto& a : intervals) {
        if (a[0] > left && a[1] > right) {
            left = a[0];
            ans++;
        }
        right = max(right, a[1]);
    }
    return ans;
}
```
