# 1539. Kth Missing Positive Number

## 1539_01.cpp

```cpp
int findKthPositive(vector<int>& arr, int k) {
    if (arr.empty() || k < arr[0]) return k;

    int pre = 0;
    for (int cur : arr) {
        if (cur - pre - 1 >= k)
            return pre + k;
        k -= cur - pre - 1;
        pre = cur;
    }
    return arr.back() + k;
}
```

## 1539_02.cpp

```cpp
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        if (arr[i] - (i + 1) >= k)
            return i + k;

    return n + k;
}
```
