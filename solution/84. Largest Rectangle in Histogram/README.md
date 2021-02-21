# 84. Largest Rectangle in Histogram

## 解釋：

每次遇到下降的柱 H[i] 時，

排在 i 前面、並且比 H[i] 高的柱，它們能夠組成的最大面積都可以分別計算了。

## Code

```cpp
int largestRectangleArea(vector<int>& H) {
    H.insert(begin(H), 0);
    H.push_back(0);
    stack<int> st;
    st.push(0);

    int ans = 0;
    for (int i = 1; i < H.size(); ++i) {
        while (H[st.top()] > H[i]) {
            int h = H[st.top()]; st.pop();
            int w = i - st.top() - 1;
            ans = max(ans, h * w);
        }
        st.push(i);
    }
    return ans;
}
```
