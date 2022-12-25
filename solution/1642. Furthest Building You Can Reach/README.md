# 1642. Furthest Building You Can Reach

## Solution: 後悔貪心

### 寫法一：

在梯子不夠用時，才後悔、自己以前的某一步操作，其實可以用磚頭替代。

```cpp
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int, vector<int>, greater<>> q;

    for (int i = 1; i < n; ++i) {
        int need = heights[i] - heights[i - 1];
        if (need <= 0)
            continue;
        q.push(need);
        if (q.size() > ladders) {
            if (q.top() <= bricks) {
                bricks -= q.top();
                q.pop();
            } else {
                return i - 1;
            }
        }
    }
    return n - 1;
}
```

### 寫法二：

先用磚頭，不夠磚頭時，才後悔、自己以前使用最多磚頭的那一步，其實可以用梯子替代。

```cpp
int furthestBuilding(vector<int>& H, int bricks, int ladders) {
    int n = H.size();
    priority_queue<int> pq;
    int i = 0;
    for (; i < n - 1; ++i) {
        if (H[i] >= H[i + 1]) continue;

        int gap = H[i + 1] - H[i];
        if (bricks >= gap) {
            bricks -= gap;
            pq.push(gap);
        } else if (ladders > 0) {
            --ladders;
            if (!pq.empty() && pq.top() > gap) {
                bricks += pq.top(), pq.pop();
                bricks -= gap;
                pq.push(gap);
            }
        } else {
            break;
        }
    }
    return i;
}
```
