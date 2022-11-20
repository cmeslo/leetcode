# 581. Shortest Unsorted Continuous Subarray

## Solution 1: sort + compare

- Time complexity: ```O(nlogn)```
- Space complexity: ```O(n)```

```cpp
int findUnsortedSubarray(vector<int>& nums) {
    vector<int> copies(nums);
    sort(begin(copies), end(copies));

    int n = nums.size();
    int l = n - 1, r = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != copies[i]) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    return l < r ? r - l + 1 : 0;
}
```

## Solution 2: 使用 monotonic stack 找到不合理的位置

- Time complexity: ```O(n)```
- Space complexity: ```O(n)```

```cpp
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = n, r = -1;
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            l = min(l, st.top());
            st.pop();
        }
        st.push(i);
    }
    if (st.size() == n) return 0;

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            r = max(r, st.top());
            st.pop();
        }
        st.push(i);
    }
    return r - l + 1;
}
```

也可以不使用 stack (推薦):

- Time complexity: ```O(n)```
- Space complexity: ```O(1)```

```cpp
// Runtime: 22 ms, Your runtime beats 99.39 % of cpp submissions.
// Memory Usage: 26.5 MB, Your memory usage beats 64.97 % of cpp submissions.

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = -1, r = -2;
    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 0; i < n; ++i) {
        mx = max(mx, nums[i]);
        if (mx > nums[i])
            r = i;
    }

    for (int i = n - 1; i >= 0; --i) {
        mn = min(mn, nums[i]);
        if (mn < nums[i])
            l = i;
    }

    return r - l + 1;
}

// 這種做法與 stack 的原理其實是一樣的:

// 我用 正向遞增 monotnoic stack 是找到第一個不合理的位置 i
// 這個不合理的 i 其實就是指: 在這個 i 後面存在一個比 nums[i] 更小的數字
// 尋找時要由後向前找

// 我用 反向遞減 monotnoic stack 是找到最後一個不合理的位置 i
// 這個不合理的 i 其實就是指: 在這個 i 前面存在一個比 nums[i] 更大的數字
// 尋找時要由前向後找
```

## Solution 3: 找出不合理值（降序）中的 最小值 和 最大值

### 解釋：

1. 第一次迭代：找出不合理值（降序）中的 最小值 和 最大值；
2. 第二次迭代：找出它們的對應 index。

- Time complexity: ```O(n)```
- Space complexity: ```O(1)```

### Code

```cpp
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();

    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            mn = min(mn, nums[i + 1]);
            mx = max(mx, nums[i]);
        }
    }
    if (mn > mx) return 0;

    int l = -2, r = -1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > mn) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] < mx) {
            r = i;
            break;
        }
    }
    return r - l + 1;
}
```
