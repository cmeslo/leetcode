# 1342. Number of Steps to Reduce a Number to Zero

## Solution 1，模擬過程：

例子：14 -> 01110

目標：令 01110 變成 00000

```
01110 --> 00111 右移
00111 --> 00110 減1
00110 --> 00011 右移
00011 --> 00010 減1
00010 --> 00001 右移
00001 --> 00000 減1
```
一共 6 次操作。

### Code (1342_01.cpp)

```cpp
int numberOfSteps (int num) {
    int ans = 0;
    while (num) {
        ans += (num & 1) ? 2 : 1;
        num >>= 1;
    }
    return max(0, ans - 1);
}
```

## Solution 2，計算：

例子：14 -> 01110

目標：令 01110 變成 00000

答案 = 要右移的次數 + 要減1的次數 = 3 + 3 = 6

1. <strong>要右移的次數</strong>：就是不斷右移，直至變成 00001，
    - 方法一： ```31 - __builtin_clz(num)```；
    - 方法二：  ```log2(num)```，比如 ```log2(14) = 3.8``` -> 3 次（為了去除全部 1，原本要右移 4 次，但這裡少了一次，相當於變成 00001，但剛剛好對應這一題，因為最後 00001 只要一次減 1 操作，不需要再右移）。

2. <strong>要減1的次數</strong>：相當於1的數目，每個1代表要做一次減1操作，C++ 可以使用 ```__builtin_popcount(num)```、或者自己數 ```n & (n - 1)```。

所以答案 = ```31 - __builtin_clz(num) + __builtin_popcount(num)``` = ```log2(num) + __builtin_popcount(num)```

注意 C++的 ```log2``` 和 ```__builtin_clz``` 都不接受 0 作為參數。

### Code (1342_02.cpp)

```cpp
int numberOfSteps (int num) {
    return num ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
}
```

or

```cpp
int numberOfSteps (int num) {
    return num ? log2(num) + __builtin_popcount(num) : 0;
}
```
