# 1696. Jump Game VI

## 解釋

維護一個<strong>單向遞減隊列</strong>，隊列裡的元素代表 ```{i, 包含nums[i]的 maximum score}```。

當遍歷到 i 時，queue裡最左邊的元素就是在範圍[i - k, i - 1] 內的 maximum score，

同時利用<strong>滑動窗口</strong>，每次都檢查隊列的最左邊，如果脫離了 k 的範圍，就移除掉。

例子 (為簡化、這裡隊列元素只寫 maximum score)：
```
10,-5,-2,4,0,3     k = 3

[10],-5,-2,4,0,3
  ^                queue: [10]

[10,-5],-2,4,0,3
     ^             queue: [10],   cur = -5 + 10 = 5
                          [10],   !(10 <= cur), 保留 10
                          [10,5], push_back(cur)
                          檢查如果queue的front對應的index脫離了window, 要pop_front

[10,-5,-2],4,0,3
        ^          queue: [10,5], cur = -2 + 10 = 8
                          [10],   5 <= cur, pop_back()
                          [10],   !(10 <= cur), 保留 10
                          [10,8], push_back(cur)
                          檢查如果queue的front對應的index脫離了window, 要pop_front

[10,-5,-2,4],0,3
          ^        queue: [10,8], cur = 4 + 10 = 14
                          [10],   8 <= cur, pop_back()
                          [],     10 <= cur, pop_back()
                          [14],   push_back(cur)
                          檢查如果queue的front對應的index脫離了window, 要pop_front

10,[-5,-2,4,0],3
            ^      queue: [14],  cur = 0 + 14 = 14
                          [],    14 <= cur, pop_back()
                          [14],  push_back(cur)
                          檢查如果queue的front對應的index脫離了window, 要pop_front

10,-5,[-2,4,0,3]
              ^    queue: [14],  cur = 3 + 14 = 17
                          [],    14 <= cur, pop_back()
                          [17],  push_back(cur)
                          檢查如果queue的front對應的index脫離了window, 要pop_front
```
答案就是 queue.back()，17

即使隊列內有其他值比queue.back()大，也只能取back()，因為要 reach the last index。

## Solution

```cpp
int maxResult(vector<int>& nums, int k) {
    int n = nums.size();

    deque<pair<int, int>> q; // <index, max_value at index>
    q.push_back({0, nums[0]});

    for (int i = 1; i < n; ++i) {
        int cur = nums[i] + q.front().second;

        while (!q.empty() && cur >= q.back().second)
            q.pop_back();

        q.push_back({i, cur});

        if (q.front().first <= i - k)
            q.pop_front();
    }

    return q.back().second;
}
```
