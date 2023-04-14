# 692. Top K Frequent Words

## Solution 1: Sort

```cpp
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    for (string& w : words)
        ++m[w];

    vector<pair<int, string>> A;
    for (auto [word, cnt] : m)
        A.push_back({cnt, word});
    sort(A.begin(), A.end(), [](auto& a, auto& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    vector<string> res;
    for (int i = 0; i < k; ++i)
        res.push_back(A[i].second);
    return res;
}
```

## Solution 2: Heap (推薦)

```cpp
vector<string> topKFrequent(vector<string>& words, int k) {
    using psi = pair<string, int>;

    unordered_map<string, int> m;
    for (string& w : words)
        ++m[w];

    auto cmp = [](auto& a, auto& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    priority_queue<psi, vector<psi>, decltype(cmp)> pq(cmp);
    for (auto it : m) {
        pq.push(it);
        if (pq.size() > k)
            pq.pop();
    }

    vector<string> res(k);
    for (int i = k - 1; i >= 0; --i) {
        res[i] = pq.top().first;
        pq.pop();
    }
    return res;
}
```
