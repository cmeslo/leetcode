# 1646. Get Maximum in Generated Array

```cpp
int getMaximumGenerated(int n) {
    if (n == 0) return 0;

    vector<int> A(n + 1);
    int ans = A[1] = 1;
    for (int i = 2; i <= n; ++i) {
        A[i] = A[i / 2] + (i % 2 ? A[i / 2 + 1] : 0);
        ans = max(ans, A[i]);
    }
    return ans;
}
```
