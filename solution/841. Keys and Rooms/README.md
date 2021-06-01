# 841. Keys and Rooms

## Solution 1 - BFS

```cpp
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<int> visited(n);

    int remain = n - 1;
    queue<int> q({0});
    ++visited[0];
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (int key : rooms[i]) {
            if (visited[key]++) continue;
            if (--remain == 0) return true;
            q.push(key);
        }
    }
    return remain == 0;
}
```

## Solution 2 - DFS

```cpp
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    stack<int> dfs({0});
    vector<int> visited(n);
    ++visited[0];

    int remain = n - 1;
    while (!dfs.empty()) {
        int i = dfs.top(); dfs.pop();
        for (int key : rooms[i]) {
            if (visited[key]++) continue;
            dfs.push(key);
            if (--remain == 0) return true;
        }
    }

    return remain == 0;
}
```
