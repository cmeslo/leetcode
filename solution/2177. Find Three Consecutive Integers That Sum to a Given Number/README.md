# 2177. Find Three Consecutive Integers That Sum to a Given Number

```cpp
vector<long long> sumOfThree(long long num) {
    if (num % 3) return {};
    long x = num / 3;
    return {x - 1, x, x + 1};
}
```
