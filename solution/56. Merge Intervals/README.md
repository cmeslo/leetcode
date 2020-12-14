# 56. Merge Intervals


```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    sort(begin(intervals), end(intervals), [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        auto& end = ans.back()[1];
        if (end < intervals[i][0])
            ans.push_back(intervals[i]);
        else
            end = max(end, intervals[i][1]);
    }

    return ans;
}
```
