# 1345. Jump Game IV

## BFS (1345.cpp)

在普通BFS之上添加兩點優化：

1. 添加 visited 記錄是否已訪問
2. 在 map 裡刪除訪問過的元素，避免出現大量相同元素時，不斷loop，例如 ```[7,7,7,7,7,7,7,...]```

```cpp
int minJumps(vector<int>& arr) {
    int n = arr.size();

    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i)
        m[arr[i]].push_back(i);

    int ans = 0;
    vector<int> visited(n);
    queue<int> q;
    visited[0] = 1; // 先設成visited再放入q會好一點，通常可以避免q裡有重複元素
    q.push(0);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int i = q.front(); q.pop();
            if (i == n - 1) return ans;
            if (i - 1 >= 0 && !visited[i - 1]++) q.push(i - 1); // key point 1 for not TLE
            if (i + 1 < n && !visited[i + 1]++) q.push(i + 1);
            auto it = m.find(arr[i]);
            if (it == m.end()) continue;
            for (int next : m[arr[i]])
                if (!visited[next]++) q.push(next);
            m.erase(it); // key point 2 for not TLE
        }
        ++ans;
    }

    return n - 1;
}
```
