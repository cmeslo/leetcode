# 374. Guess Number Higher or Lower

## Solution: Binary search

```cpp
int guessNumber(int n) {
    int l = 1, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (guess(m) == 1)
            l = m + 1;
        else
            r = m;
    }
    return l;
}
```
