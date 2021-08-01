# 204. Count Primes

## Solution: 質數篩

[埃拉托斯特尼篩法](https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95)

```cpp
int countPrimes(int n) {
    int ans = 0;
    vector<bool> isPrimes(n, true);
    for (int x = 2; x < n; ++x) {
        if (isPrimes[x]) {
            ++ans;
            for (int i = 2; i * x < n; ++i)
                isPrimes[i * x] = false;
        }
    }
    return ans;
}
```
