# 57. Insert Interval

## 57_01.cpp, 57_03.cpp

兩種做法的思路一樣，分開三段討論、再循環處理 

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {     
    int i = 0;
    while (i < intervals.size() && intervals[i][0] < newInterval[0]) i++;
    intervals.insert(intervals.begin() + i, newInterval);

    vector<vector<int>> ans;
    for (const auto& interval : intervals) {
        if (ans.empty() || ans.back()[1] < interval[0]) {
            ans.push_back(interval);
        } else {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    return ans;
}
```

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int start = newInterval[0], end = newInterval[1];
    vector<vector<int>> ans;

    int i = 0, n = intervals.size();
    while (i < n && intervals[i][1] < start) {
        ans.push_back(intervals[i++]);
    }

    while (i < n && !(end < intervals[i][0])) {
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        i++;
    }
    ans.push_back({start, end});

    while (i < n) {
        ans.push_back(intervals[i++]);
    }

    return ans;
}
```

## 57_02.cpp

同樣是分三段，但前、後段另外存放起來，中間段特殊處理，最後再合併。

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> l, r;
    int start = newInterval[0];
    int end = newInterval[1];

    for (const auto& interval : intervals) {
        if (interval[1] < start) {
            l.push_back(interval);
        } else if (end < interval[0]) {
            r.push_back(interval);
        } else {
            start = min(start, interval[0]);
            end = max(end, interval[1]);
        }
    }

    vector<vector<int>> ans(std::move(l));
    ans.push_back({start, end});
    ans.insert(ans.end(), r.begin(), r.end());

    return ans;
}
```

## 57_04.cpp

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    auto it = lower_bound(intervals.begin(), intervals.end(), newInterval);
    intervals.insert(it, newInterval);

    vector<vector<int>> res;
    for (auto& in : intervals) {
        if (!res.empty() && res.back()[1] >= in[0]) {
            res.back()[1] = max(res.back()[1], in[1]);
        } else {
            res.push_back(in);
        }
    }

    return res;
}
```
