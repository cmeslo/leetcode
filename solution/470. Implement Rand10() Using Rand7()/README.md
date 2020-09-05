# 470. Implement Rand10() Using Rand7()

## 470_01.cpp

錯誤的方法：
```cpp
int rand10() {
    return (rand7() + rand7()) % 10 + 1;
}
```

這類題目的萬用解決方法：

```cpp
// Your runtime beats 99.23 % of cpp submissions.
int rand10() {
    int index = INT_MAX;
    while (index >= 40)
        index = 7 * (rand7() - 1) + (rand7() - 1);
    return index % 10 + 1;
}
```

參考：https://www.youtube.com/watch?v=Wyauxe92JJA


## 470_02.cpp

另一種方法：

```cpp
// Your runtime beats 91.93 % of cpp submissions.
int rand10() {
    int a = 7, b = 7;

    while (a == 7)
        a = rand7();
    a %= 2;

    while (b > 5)
        b = rand7();

    return 5 * a + b;
}
```
