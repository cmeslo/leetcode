# 436. Find Right Interval

## 436_01.cpp 使用 map 的 lower_bound 方法

```cpp
// Runtime: 156 ms
// Memory Usage: 28.5 MB

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<int> ans;
    map<int, int> m;

    for (int i = 0; i < n; i++)
        m[intervals[i][0]] = i;

    for (auto& interval : intervals) {
        auto it = m.lower_bound(interval[1]);
        if (it == m.end()) ans.push_back(-1);
        else ans.push_back(it->second);
    }

    return ans;
}
```

## 436_02.cpp 使用 binary search 尋找 lower bound

 lower bound - 第一個 first 值大於等於目標 end 值的 intervals

```cpp
// Runtime: 124 ms
// Memory Usage: 24.1 MB

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> sorted(n); // {start, index}
        
        for (int i = 0; i < n; ++i)
            sorted[i] = {intervals[i][0], i};
        
        sort(sorted.begin(), sorted.end());
        
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i)
            ans[i] = binary_search(sorted, intervals[i][1]);
        
        return ans;
    }
    
private:
    int binary_search(vector<pair<int, int>>& sorted, int end) {
        if (sorted.back().first < end) return -1;
        
        int l = 0, r = sorted.size();
        while (l < r) { // lower_bound
            int mid = l + (r - l) / 2;
            int mid_start = sorted[mid].first;
            if (mid_start < end) l = mid + 1;
            else r = mid;
        }
        
        return sorted[l].second;
    }
};
```
