# 1338. Reduce Array Size to The Half

## Solution: Greedy

由出現次數最多的數字開始移除，當發現移除了超過一半的數字就可以停止。

```cpp
int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    for (int x : arr)
        ++m[x];

    vector<int> A;
    for (auto [x, cnt] : m)
        A.push_back(cnt);

    sort(A.rbegin(), A.rend());

    int cnt = 0;
    for (int i = 0; i < A.size(); ++i) {
        cnt += A[i];
        if (cnt >= arr.size() / 2)
            return i + 1;
    }
    return -1;
}
```
