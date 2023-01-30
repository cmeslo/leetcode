# 458. Poor Pigs

## Solution: Math

```cpp
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs = 0;
    while (pow(minutesToTest / minutesToDie + 1, pigs) < buckets)
        ++pigs;
    return pigs;
}
```
