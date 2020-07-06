# 264. Ugly Number II

## 264_01.cpp

方法一，計算並保存所有由 ```ugly number``` 2, 3, 5 所構成的數字，

然後排序，直接就可以取到想要的第 n 位。

```cpp
int nthUglyNumber(int n) {
    vector<int> ugly_nums;
    for (long a = 1; a < INT_MAX; a*=2)
        for (long b = a; b < INT_MAX; b*=3)
            for (long c = b; c < INT_MAX; c*=5)
                ugly_nums.push_back(c);
    sort(ugly_nums.begin(), ugly_nums.end());
    return ugly_nums[n-1];
}
```

## 264_02.cpp

方法二，方法一的優化版，添加 ```static``` 關鍵字，讓計算只做一次，

leetcode 裡多次調用都不用重新算過，運行時間大幅下降

```cpp
int nthUglyNumber(int n) {
    static vector<int> ugly_nums;
    if (ugly_nums.empty()) {
        for (long a = 1; a < INT_MAX; a*=2)
            for (long b = a; b < INT_MAX; b*=3)
                for (long c = b; c < INT_MAX; c*=5)
                    ugly_nums.push_back(c);
        sort(ugly_nums.begin(), ugly_nums.end());
    }
    return ugly_nums[n-1];
}
```

## 264_03.cpp

方法三，leetcode 官方提示的做法，

三個 index i2, i3, i5 分別從 0 開始向 n 移動

各位置對應的```ugly number```再分別乘以 2, 3, 5，每次取最小的結果（注意，如果有相同結果，則index一起向前移動），

最後放到 ugly number 結果集裡。

```cpp
int nthUglyNumber(int n) {
    vector<int> uglys{1};
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 0; i < n; i++) {
        int next2 = uglys[i2]*2;
        int next3 = uglys[i3]*3;
        int next5 = uglys[i5]*5;
        int next = min(next2, min(next3, next5));
        uglys.push_back(next);
        if (next == next2) i2++;
        if (next == next3) i3++;
        if (next == next5) i5++;
    }
    return uglys[n-1];
}
```

使用 static 優化，不用每次從頭開始算：

```cpp
int nthUglyNumber(int n) {
    static vector<int> uglys{1};
    static int i2 = 0, i3 = 0, i5 = 0;
    while (uglys.size() < n) {
        const int next2 = uglys[i2]*2;
        const int next3 = uglys[i3]*3;
        const int next5 = uglys[i5]*5;
        const int next = min(next2, min(next3, next5));
        uglys.push_back(next);
        if (next == next2) i2++;
        if (next == next3) i3++;
        if (next == next5) i5++;
    }
    return uglys[n-1];
}
```
