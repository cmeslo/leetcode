# 2104. Sum of Subarray Ranges

## Solution 1: Brute force

Time: ```O(n^2)```

```cpp
// Runtime: 154 ms, Your runtime beats 20.73 % of cpp submissions.

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long res = 0;
    for (int i = 0; i < n; ++i) {
        int mx = nums[i], mn = nums[i];
        for (int j = i; j < n; ++j) {
            mx = max(mx, nums[j]);
            mn = min(mn, nums[j]);
            res += mx - mn;
        }
    }
    return res;
}
```

## Solution 2: Monotonic stack

```
  sum of subarray ranges
= sum of subarray maximums - sum of subarray minimums
```

Time: ```O(n)```

```cpp
// Runtime: 23 ms, Your runtime beats 88.75 % of cpp submissions.

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> nextSmaller(n, n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            nextSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> prevSmallerOrEqual(n, -1);
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            prevSmallerOrEqual[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> nextGreater(n, n);
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            nextGreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> prevGreaterOrEqual(n, -1);
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            prevGreaterOrEqual[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += (long long)nums[i] * (i - prevGreaterOrEqual[i]) * (nextGreater[i] - i);
        res -= (long long)nums[i] * (i - prevSmallerOrEqual[i]) * (nextSmaller[i] - i);
    }
    return res;
}
```
