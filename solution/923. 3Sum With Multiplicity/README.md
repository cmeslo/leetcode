# 923. 3Sum With Multiplicity

## Solution 1 : hashmap + 2 sum

```cpp
// Your runtime beats 14.62 % of cpp submissions.

int threeSumMulti(vector<int>& arr, int target) {
    const int mod = 1e9 + 7;
    int n = arr.size();
    int ans = 0;
    unordered_map<int, int> m;

    for (int i = 1; i < n; ++i) {
        if (m.count(target - arr[i]))
            ans = (ans + m[target - arr[i]]) % mod;

        for (int j = i - 1; j >= 0; --j)
            ++m[arr[i] + arr[j]];
    }

    return ans;
}
```

or

```cpp
int threeSumMulti(vector<int>& arr, int target) {
    unordered_map<int, int> m;

    long ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            int t = target - arr[i] - arr[j];
            if (m.count(t)) ans += m[t];
        }
        ++m[arr[i]];
    }
    return ans % 1000000007;
}
```

## Solution 2 : math - combination

### 寫法一：用數組

```cpp
// Your runtime beats 92.66 % of cpp submissions. - 8 ms
// Your memory usage beats 81.86 % of cpp submissions.

int threeSumMulti(vector<int>& arr, int target) {
    vector<long> m(101);
    for (int x : arr) ++m[x];

    long ans = 0;
    for (int a = 0; a <= target / 3; ++a) { // for (int a = 0; a <= target; ++a) 也可以
        for (int b = a; b <= target / 2; ++b) { // for (int b = a; b <= target; ++b) 也可以
            int c = target - a - b;
            if (0 <= c && c <= 100 && b <= c) { // 保證 a <= b <= c
                if (!m[a] || !m[b] || !m[c]) continue;
                if (a == b && b == c)
                    ans += m[a] * (m[a] - 1) * (m[a] - 2) / 6;
                else if (a == b && b != c)
                    ans += m[a] * (m[a] - 1) / 2 * m[c];
                else if (a != b && b == c)
                    ans += m[a] * m[b] * (m[b] - 1) / 2;
                else if (a < b && b < c)
                    ans += m[a] * m[b] * m[c];
            }
        }
    }
    return ans % 1000000007;
```

### 寫法二：用map

```cpp
int threeSumMulti(vector<int>& arr, int target) {
    const int mod = 1e9 + 7;
    unordered_map<int, long> c;
    for (int a : arr) ++c[a];

    long ans = 0;
    for (auto it1 : c) {
        for (auto it2 : c) {
            int i = it1.first, j = it2.first, k = target - i - j; // 這裡的 i, j, k 不是index
            if (!c.count(k)) continue;
            if (i == j && j == k)
                ans += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
            else if (i == j && j != k)
                ans += c[i] * (c[i] - 1) / 2 * c[k];
            else if (i < j && j < k)
                ans += c[i] * c[j] * c[k];
        }
    }

    return ans % mod;
}
```

### 為什麼用數組，要加多一個條件 ```if (i != j && j == k)```

```
if (i == j && j == k)
    ans += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
else if (i == j && j != k)
    ans += c[i] * (c[i] - 1) / 2 * c[k];
```
```cpp
else if (i != j && j == k)
    ans += c[i] * c[j] * (c[j] - 1) / 2;
```
```
else if (i < j && j < k)
    ans += c[i] * c[j] * c[k];
```

而用unordered_map不需要？
因為用數組的情況下，保證了 i <= j <= k，比如 [2, 2, 3, 3, 4] target = 8

#### 用 map 迭代時會出現的Combination
```
[2, 3, 3],
       ^--不合法，上述的if條件都不符合，所以會跳過
[3, 2, 3]
       ^--不合法，上述的if條件都不符合，跳過
[3, 3, 2]
       ^--合法，i == j && j != k

[2, 2, 4]
       ^--合法，i == j && j != k
```
#### 用 array 迭代時會出現的Combination
```
[2, 3, 3]
       ^--合法，因為兩個for循環限制了 i <= j，再用一個if句限制 j <= k

[2, 2, 4]
       ^--合法，也是可以的
[2, 4, 2]
       ^--不合法，因為不符合 j <= k，跳過
```
其實就是如何確保 [a, a, b] 這個 Combination 只會出現一次計算。
