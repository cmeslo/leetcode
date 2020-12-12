# 845. Longest Mountain in Array

## 845_01.cpp

先從左、右分別開始走，記錄每個數字上 遞增 和 遞減 的數目

最後再遍歷一次計算最大長度（當自己是山頂，把左、右分別走到山腳的長度相加）

```cpp
int longestMountain(vector<int>& A) {
    int n = A.size();
    vector<int> increasing(n), decreasing(n);

    for (int i = 1; i < n; ++i)
        if (A[i - 1] < A[i]) increasing[i] = increasing[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i)
        if (A[i] > A[i + 1]) decreasing[i] = decreasing[i + 1] + 1;

    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (increasing[i] && decreasing[i])
            ans = max(ans, increasing[i] + 1 + decreasing[i]);

    return ans;
}
```

or 

```cpp
int longestMountain(vector<int>& A) {
    int n = A.size();
    vector<int> up(n), down(n);

    up[0] = 1;
    for (int i = 1; i < n; ++i)
        up[i] = A[i - 1] < A[i] ? up[i - 1] + 1 : 1;

    down[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
        down[i] = A[i] > A[i + 1] ? down[i + 1] + 1 : 1;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i)
        if (up[i] != 1 && down[i] != 1)
            ans = max(ans, up[i] + down[i] - 1);

    return ans >= 3 ? ans : 0;
}
```


## 845_02.cpp

一次遍歷

```cpp
int longestMountain(vector<int>& A) {
    int n = A.size();

    int ans = 0;
    int inc = 0, dec = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (dec && A[i] < A[i + 1] || A[i] == A[i + 1])
            inc = dec = 0;

        inc += A[i] < A[i + 1];
        dec += A[i] > A[i + 1];

        if (inc && dec)
            ans = max(ans, inc + 1 + dec);
    }

    return ans;
}
```
