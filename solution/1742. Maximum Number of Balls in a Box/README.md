# 1742. Maximum Number of Balls in a Box

## 第一版

```cpp
int countBalls(int lowLimit, int highLimit) {
    map<int, int> m;
    int ans = 0;
    for (int x = lowLimit; x <= highLimit; ++x) {
        int sum = 0, tmp = x;
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        ans = max(ans, ++m[sum]);
    }
    return ans;
}
```

## 第二版

由於 ```1 <= lowLimit <= highLimit <= 10^5```，所以 box id的最大值有：

```10^5 > 100000 -> 99999 -> 9 + 9 + 9 + 9 + 9 = 45```

所以可以不用 map：

```cpp
int countBalls(int lowLimit, int highLimit) {
    vector<int> boxes(46);
    int ans = 0;
    for (int x = lowLimit; x <= highLimit; ++x) {
        int sum = 0, num = x;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        ans = max(ans, ++boxes[sum]);
    }
    return ans;
}
```
