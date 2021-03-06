# 910. Smallest Range II

## Explanation:
![Explanation](910.png)


## Code:

```cpp
int smallestRangeII(vector<int>& A, int K) {
    sort(begin(A), end(A));

    int n = A.size();
    int mn = A[0], mx = A[n - 1];
    int ans = mx - mn; // 頭尾一起 +K 或 -K 的情況

    for (int i = 0; i < n - 1; ++i) {
        mn = min(A[0] + K, A[i + 1] - K);
        mx = max(A[i] + K, A[n - 1] - K);
        ans = min(ans, mx - mn);
    }

    return ans;
}
```
