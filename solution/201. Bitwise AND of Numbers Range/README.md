# 201. Bitwise AND of Numbers Range

Common prefix

```cpp
int rangeBitwiseAnd(int left, int right) {
    int res = 0;
    for (int i = 31; i >= 0; --i) {
        int bitL = left & (1 << i);
        int bitR = right & (1 << i);

        if (bitL && bitR)
            res |= (1 << i);
        else if (bitL || bitR)
            break;
    }
    return res;
}
```

or

```cpp
int rangeBitwiseAnd(int left, int right) {
    int i = 0;
    while (left != right) {
        left >>= 1;
        right >>= 1;
        ++i;
    }
    return left << i;
}
```
