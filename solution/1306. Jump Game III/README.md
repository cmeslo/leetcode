# 1306. Jump Game III

bfs

```cpp
// 60 ms
// Your runtime beats 90.96 % of cpp submissions.

bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int index = q.front(); q.pop();
        int left = index - arr[index];
        int right = index + arr[index];

        if (arr[index] == 0) return true;

        if (left >= 0 && arr[left] != -1) q.push(left);
        if (right < n && arr[right] != -1) q.push(right);

        arr[index] = -1;
    }

    return false;
}
```
