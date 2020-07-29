# 621. Task Scheduler

## 數學方法 - 621_01.cpp：
```cpp
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> m;
    int maxFreq = 0, cycle = 0;

    for (char& c : tasks)
        maxFreq = max(maxFreq, ++m[c]);

    for (auto& it : m)
        if (it.second == maxFreq) cycle++;

    int ans = (maxFreq - 1) * (n + 1) + cycle;

    return ans < tasks.size() ? tasks.size() : ans;
}
```

或者

```cpp
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    int maxFreq = 0, cycle = 0;

    for (char& c : tasks)
        maxFreq = max(maxFreq, ++freq[c - 'A']);

    for (int f : freq)
        if (f == maxFreq) cycle++;

    int ans = (maxFreq - 1) * (n + 1) + cycle;

    return ans < tasks.size() ? tasks.size() : ans;
}
```

## 模擬方法 (Priority queue) - 621_02.cpp:
```cpp
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> m;
    for (const char& c : tasks)
        m[c]++;

    priority_queue<pair<int, char>> pq;
    for (auto it : m)
        pq.push(make_pair(it.second, it.first));

    int ans = 0;
    while (!pq.empty()) {
        vector<char> tmp;
        for (int i = 0; i < n+1; i++) {
            if (pq.empty()) break;
            tmp.push_back(pq.top().second);
            m[pq.top().second]--;
            pq.pop();
        }

        for (const char& c : tmp)
            if (m[c]) pq.push(make_pair(m[c], c));

        ans += pq.empty() ? tmp.size() : n+1;
    }

    return ans;
}
```

或者

```cpp
int leastInterval(vector<char>& tasks, int n) {

    int res = 0, partLen = n + 1;
    unordered_map<char, int> m;
    priority_queue<int> q;

    for (int t : tasks) ++m[t];
    for (auto a : m) q.push(a.second);

    while(!q.empty()) {
        vector<int> part;
        for (int i = 0; i < partLen; ++i) {
            if (!q.empty()) {
                part.push_back(q.top()); q.pop();
            }
        }
        for (int p : part) if (--p > 0) q.push(p);

        res += q.empty() ? part.size() : partLen;
    }
    return res;
}
```
