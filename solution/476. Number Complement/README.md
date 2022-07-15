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
