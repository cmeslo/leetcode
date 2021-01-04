# 1711. Count Good Meals

## Brute force (TLE)

```cpp
int countPairs(vector<int>& deliciousness) {
    const int k = 1e9 + 7;
    auto& D = deliciousness;
    int n = D.size();

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = (D[i] % k + D[j] % k) % k;
            if (sum == 0) continue;
            if ((sum & (sum - 1)) == 0)
                ++ans;
        }
    }

    return ans;
}
```

## Optimize with the concept of two sum (1711.cpp)

```cpp
int countPairs(vector<int>& deliciousness) {
    const int k = 1e9 + 7;
    auto& D = deliciousness;
    int n = D.size();
    unordered_map<int, int> m;

    int ans = 0;
    for (int d : D) {
        for (int j = 0; j < 22; ++j) {
            int pow = 1 << j;
            if (m.count(pow - d)) {
                ans += m[pow - d];
                ans %= k;
            }
        }
        ++m[d];
    }

    return ans;
}
```

## Use array instend of map (not necessary)

```cpp
// 344 ms

int countPairs(vector<int>& deliciousness) {
    const int k = 1e9 + 7;
    auto& D = deliciousness;
    int n = D.size();
    vector<int> m((1 << 21) + 1);

    long ans = 0;
    for (int d : D) {
        for (int j = 0; j <= 21; ++j) {
            int pow = 1 << j;
            if (pow >= d)
                ans += m[pow - d];
        }
        ++m[d];
    }

    return ans % k;
}
```
