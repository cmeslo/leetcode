# 347. Top K Frequent Elements

## Solution 1: Bucket sort

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int max_freq = 1;
    for (const int num : nums) {
        max_freq = max(max_freq, ++count[num]);
    }

    unordered_map<int, vector<int>> buckets;
    for (auto& kv : count) {
        buckets[kv.second].push_back(kv.first);
    }

    vector<int> ans;
    for (int i = max_freq; i >= 1; i--) {
        auto it = buckets.find(i);
        if (it == buckets.end()) continue;
        ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        if (ans.size() == k) return ans;
    }
    return ans;
}
```

## Solution 2: Heap

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int x : nums) {
        m[x]++;
    }

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (auto [x, count] : m) {
        pq.push({count, x});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}
```
