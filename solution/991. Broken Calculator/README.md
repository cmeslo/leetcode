# 991. Broken Calculator

## 解釋：

正向操作時，可以先 ```x2``` 再 ```-1```、或者中途 ```-1``` 再 ```x2```，範圍不斷擴大，難以計算

1. 逆向思維，反過來收斂 Y，```x2``` 變 ```/2```、```-1``` 變 ```+1```；
2. Y是奇數時，應該把 Y+1；
3. Y是偶數時，究竟正向最後應該 ```-1``` 得到 Y ，還是 ```x2``` 得到 Y？

- 答案應該是 ```x2``` 才對，更偏向喜歡 ```x2``` 是因為 ```(Y + 1 + 1) / 2``` 等價於 ```Y / 2 + 1``` （較少的操作達到相同的效果）。

### Code
```cpp
int brokenCalc(int X, int Y) {
    if (X >= Y) return X - Y;

    if (Y % 2)
        return brokenCalc(X, Y + 1) + 1;
    else
        return brokenCalc(X, Y / 2) + 1;
}
```

or

```cpp
int brokenCalc(int X, int Y) {
    if (X >= Y) return X - Y;
    return 1 + brokenCalc(X, Y % 2 ? Y + 1 : Y / 2);
}
```
