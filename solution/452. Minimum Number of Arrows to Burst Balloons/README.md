# 452. Minimum Number of Arrows to Burst Balloons #

## 452_01.cpp ##

1. sort by end
2. shoot as right as possible

Your runtime beats 84.10 % of cpp submissions.

```cpp
int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;

    sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];
    });

    int shoot = 1;
    int end = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
        if (end < points[i][0]) {
            ++shoot;
            end = points[i][1];
        }
    }

    return shoot;
}
```

## 452_02.cpp ##

sort by start

Your runtime beats 94.75 % of cpp submissions.

```cpp
int findMinArrowShots(vector<vector<int>>& points) {
    sort(begin(points), end(points), [](const auto& a, const auto& b) {
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
    });

    int n = points.size();
    int arrows = 0;

    for (int i = 0; i < n; ++i) {
        int end = points[i][1];
        while (i + 1 < n && points[i + 1][0] <= end) {
            end = min(end, points[i + 1][1]);
            ++i;
        }
        ++arrows;
    }

    return arrows;
}
```
