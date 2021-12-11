# 42. Trapping Rain Water

## Solution 1: Two pass

count vertical

```cpp
int trap(vector<int>& H) {
    int n = H.size();
    vector<int> left(n), right(n);
    for (int i = 1; i < n - 1; ++i) {
        left[i] = max(H[i - 1], left[i - 1]);
        right[n - i - 1] = max(H[n - i], right[n - i]);
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int h = min(left[i], right[i]) - H[i];
        if (h > 0)
            res += h;
    }
    return res;
}
```

## Solution 2: Monotonic stack

```cpp
int trap(vector<int>& H) {
    int res = 0;
    stack<int> st;
    for (int i = 0; i < H.size(); ++i) {
        while (!st.empty() && H[st.top()] < H[i]) {
            int base = H[st.top()]; st.pop();
            if (st.empty()) break;
            int h = min(H[st.top()], H[i]) - base;
            int w = i - st.top() - 1;
            res += h * w;
        }
        st.push(i);
    }
    return res;
}
```
