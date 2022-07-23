# 1009. Complement of Base 10 Integer

兩個方法都是先求出全 1111 1111 的數，再與原數字做 相減 或 xor

## Solution 1: 減法

```cpp
int bitwiseComplement(int N) {
    if (N < 2) return 1 - N;

    int num = 2;
    while (num < N)
        num *= 2;

    return num == N ? (num - 1) : (num - 1 - N);
}
```

## Solution 2: XOR (更直觀的做法)

```
0 0 0 1 0 1 <-- n

0 0 0 1 1 1 <-- xor this

0 0 0 0 1 0
```

```cpp
int bitwiseComplement(int n) {
    int x = 1;
    while (x < n)
        x = (x << 1) | 1;

    return x ^ n;
}
```
