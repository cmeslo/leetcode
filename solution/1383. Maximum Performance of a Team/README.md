# 1383. Maximum Performance of a Team

## Solution: Sort + PQ

```cpp
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> engineers;
    for (int i = 0; i < n; ++i)
        engineers.emplace_back(efficiency[i], speed[i]);

    sort(rbegin(engineers), rend(engineers));

    long sumS = 0, res = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto& [e, s] : engineers) {
        pq.push(s);
        sumS += s;
        if (pq.size() > k) {
            sumS -= pq.top(); pq.pop();
        }
        res = max(res, sumS * e);
    }
    return res % 1000000007;
}
```
