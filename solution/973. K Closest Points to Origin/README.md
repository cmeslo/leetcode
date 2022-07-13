# 973. K Closest Points to Origin

## Solution 1: Sort

```cpp
// Runtime: 304 ms, Your runtime beats 72.17 % of cpp submissions.
// Memory Usage: 53.5 MB, Your memory usage beats 99.97 % of cpp submissions.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> dists;
        vector<vector<int>> ans;
        
        for (const vector<int>& point : points) {
            dists.push_back(calcDist(point));
        }
        
        sort(dists.begin(), dists.end());
        int distK = dists[K-1];
        
        for (const vector<int>& point : points) {
            if (calcDist(point) <= distK) {
                ans.push_back(point);
            }
        }
        return ans;
    }
    
private:
    int calcDist(const vector<int>& point) {
        return point[0] * point[0]  + point[1] * point[1];
    }
};
```

## Solution 2: Heap

```cpp
// Runtime: 284 ms, Your runtime beats 77.19 % of cpp submissions.
// Memory Usage: 61.1 MB, Your memory usage beats 81.75 % of cpp submissions.

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto cmp = [&](const vector<int>& a, const vector<int>& b) {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for (auto& p : points) {
        pq.push(p);
        if (pq.size() > k)
            pq.pop();
    }
    vector<vector<int>> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
```
