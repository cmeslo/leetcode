# 858. Mirror Reflection

## Solution: Math

```cpp
int mirrorReflection(int p, int q) {
    while (p % 2 == 0 && q % 2 == 0) {
        p >>= 1, q >>= 1;
    }
    if (p % 2 == 0) return 2;
    if (q % 2 == 0) return 0;
    return 1;
}
```

or

```cpp
int mirrorReflection(int p, int q) {
    int h = p * q / gcd(p, q);
    int m = h / q;
    int n = h / p;

    if (m % 2 == 0 && n % 2 == 1) return 2;
    if (m % 2 == 1 && n % 2 == 0) return 0;
    if (m % 2 == 1 && n % 2 == 1) return 1;
    return 3;
}

// p:
// m = odd  -> 0, 1
// m = even -> 2, 3

// q:
// n = odd  -> 1, 2
// n = even -> 0, 3
```
