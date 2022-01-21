# 633. Sum of Square Numbers

## Solution 1: Two pointers

```cpp
bool judgeSquareSum(int c) {
    long long l = 0, r = sqrt(c);
    while (l <= r) {
        long long tmp = l * l + r * r;
        if (tmp == c)
            return true;
        if (tmp < c)
            ++l;
        else
            --r;
    }
    return false;
}
```

## Solution 2: Math

```cpp
bool judgeSquareSum(int c) {
    int m = sqrt(c);
    for (long a = 0; a <= m; ++a) {
        long b = round(sqrt(c - a * a));
        if (a*a + b*b == c) return true;
    }
    return false;
}
```
