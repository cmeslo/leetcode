# 342. Power of Four

## 方法一: 循環

最初想到的方法，發現它們共通點是，二進制只有一個 ```1```，而且在 ```1``` 前出現的 ```0``` 只有偶數個

```
1:     0000 0001
4:     0000 0100 --2個零
16:    0001 0000 --4個零
64:    0100 0000 --6個零
256: 1 0000 0000 --8個零
```

```cpp
bool isPowerOfFour(int n) {
    int cnt = 0;
    if (n <= 0 || n & n-1) return false;

    while (n) {
        if (n == 1) return cnt%2 == 0;
        cnt += ((n & 1) == 0 ? 1 : 0);
        n >>= 1;
    }

    return false;
}
```

## 方法二: (num - 1) % == 0

```cpp
bool isPowerOfFour(int num) {
    return (num > 0)
        && (num & num-1) == 0
        && (num-1) % 3 == 0;
}
```

## 方法三: ```0x55555555```

根據方法一的觀察, 可以根據 ```1``` 的出現位置，得到 ```0x55555555```

```cpp
bool isPowerOfFour(int num) {
    return (num > 0)
        && (num & num-1) == 0
        && (num & 0x55555555);
}
```
