# 476. Number Complement

## Solution 1:

```cpp
int findComplement(int num) {
    int res = 0;
    int pos = 0;
    while (num) {
        res |= ((num ^ 1) & 1) << pos++;
        num >>= 1;
    }
    return res;
}
```

## Solution 2: mask

```cpp
int findComplement(int num) {
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    return ~num & ~mask;
}
```

or

```cpp
int findComplement(int num) {
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    return ~mask ^ num;
}
```
