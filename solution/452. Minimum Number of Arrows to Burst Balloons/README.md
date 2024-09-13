# 452. Minimum Number of Arrows to Burst Balloons #

## Solution: Greedy 1 (452_01.cpp) ##

1. sort by end
2. shoot as right as possible

```cpp
// Your runtime beats 84.10 % of cpp submissions.

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });

    int res = 1;
    int mx = points[0][1];
    for (auto& p : points) {
        if (p[0] > mx) {
            ++res;
            mx = p[1];
        }
    }
    return res;
}
```

## Solution: Greedy 2 (452_02.cpp) ##

1. sort by start

```cpp
// Your runtime beats 94.75 % of cpp submissions.

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

or

```cpp
int findMinArrowShots(vector<vector<int>>& P) {
    sort(P.begin(), P.end());

    int res = 1, arrowX = P[0][1];
    for (int i = 1; i < P.size(); ++i) {
        if (arrowX >= P[i][0]) {
            arrowX = min(arrowX, P[i][1]);
        } else {
          ++res;
          arrowX = P[i][1];
        }
    }
    return res;
}
```
