# 1015. Smallest Integer Divisible by K

```cpp
int smallestRepunitDivByK(int K) {
    if (K % 2 == 0 || K % 5 == 0) return -1;

    int len = 1;
    int num = 1;
    while (num % K) {
        num = (num % K) * 10 + 1;
        ++len;
    }
    return len;
}
```

A better version:

```cpp
int smallestRepunitDivByK(int K) {
    if (K % 2 == 0 || K % 5 == 0) return -1;

    int num = 0;
    for (int n = 1; n <= K; ++n) {
        num = (num * 10 + 1) % K;
        if (num == 0) return n;
    }

    return -1;
}
```
