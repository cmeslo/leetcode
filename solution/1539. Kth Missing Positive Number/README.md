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

### 解釋：

正常時：```arr[i] = i + 1```

有缺時：```arr[i] > i + 1``` ===> ```arr[i] - (i + 1) > 0```

由 ```arr[i] - (i + 1)``` 可以知道缺失了多少個數

```arr[i] - (i + 1) == k``` 是我們要的答案

答案是：由對上一個正常數字開始加回來，即 ```i + k```


```cpp
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        if (arr[i] - (i + 1) >= k)
            return i + k;

    return n + k;
}
```

## 1539_03.cpp

知道了 ```arr[i] - (i + 1) >= k``` 這個判斷條件，

就可以利用題目的特性 -- 嚴格遞增，去做binary search，找到lower bound，再加上 k。

```cpp
int findKthPositive(vector<int>& arr, int k) {
    int l = 0, r = arr.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] - (mid + 1) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l + k;
}
```

## 1539_04.cpp

暴力解法

```cpp
int findKthPositive(vector<int>& arr, int k) {
    unordered_set<int> s(begin(arr), end(arr));
    for (int x = 1; x <= arr.back(); ++x) {
        if (!s.count(x))
            --k;
        if (k == 0)
            return x;
    }
    return arr.back() + k;
}
```
