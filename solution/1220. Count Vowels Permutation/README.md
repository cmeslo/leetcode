# 1220. Count Vowels Permutation

## Solution 1: Recursion (top-down)

```cpp
// Your runtime beats 23.77 % of cpp submissions.
// Your memory usage beats 31.89 % of cpp submissions.

class Solution {
public:
    int countVowelPermutation(int n) {
        memo_.resize(5, vector<long>(n + 1));
        long ans = 0;
        ans += helper('a', n);
        ans += helper('e', n);
        ans += helper('i', n);
        ans += helper('o', n);
        ans += helper('u', n);
        return ans % kMod_;
    }
    
private:
    const int kMod_ = 1e9 + 7;
    vector<vector<long>> memo_;
    unordered_map<char, int> m_ = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    
    long helper(const char c, int n) {
        if (n == 1) return 1;
        int i = m_[c];
        if (memo_[i][n]) return memo_[i][n];
        if (c == 'a') return memo_[i][n] = helper('e', n - 1) % kMod_;
        if (c == 'e') return memo_[i][n] = (helper('a', n - 1)
                                          + helper('i', n - 1)) % kMod_;
        if (c == 'i') return memo_[i][n] = (helper('a', n - 1)
                                          + helper('e', n - 1)
                                          + helper('o', n - 1)
                                          + helper('u', n - 1)) % kMod_;
        if (c == 'o') return memo_[i][n] = (helper('i', n - 1)
                                          + helper('u', n - 1)) % kMod_;
        if (c == 'u') return memo_[i][n] = helper('a', n - 1) % kMod_;
        return 0;
    }
};
```

## Solution 2: DP (botton-up)

### 解釋

```
dp[1] = 5, {a, e, i, o, u}

xxxa + {e} => xxxae
xxxe + {a, i} => xxxea, xxxei
xxxi + {a, e, o, u} => xxxia, xxxie, xxxio, xxxiu
xxxo + {i, u} => xxxio, xxxiu
xxxu + {a} => xxxua

dp[2][a] = dp[1][e] + dp[1][i] + dp[1][u];
dp[2][e] = dp[1][a] + dp[1][i];
dp[2][i] = dp[1][e] + dp[1][o];
dp[2][o] = dp[1][i];
dp[2][u] = dp[1][i] + dp[1][o];
```

### Code

```cpp
// Your runtime beats 20.57 % of cpp submissions.
// Your memory usage beats 19.62 % of cpp submissions.

int countVowelPermutation(int n) {
    const int M = 1e9 + 7;
    unordered_map<char, int> m;
    m['a'] = 0, m['e'] = 1, m['i'] = 2, m['o'] = 3, m['u'] = 4;

    vector<vector<long>> dp(n + 1, vector<long>(5));
    for (long& x : dp[1]) x = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i][m['a']] = (dp[i - 1][m['e']] + dp[i - 1][m['i']] + dp[i - 1][m['u']]) % M;
        dp[i][m['e']] = (dp[i - 1][m['a']] + dp[i - 1][m['i']]) % M;
        dp[i][m['i']] = (dp[i - 1][m['e']] + dp[i - 1][m['o']]) % M;
        dp[i][m['o']] = dp[i - 1][m['i']];
        dp[i][m['u']] = (dp[i - 1][m['i']] + dp[i - 1][m['o']]) % M;
    }

    return accumulate(dp[n].begin(), dp[n].end(), 0L) % M;
}
```

由於 ```dp[i]``` 只與 ```dp[i - 1]``` 有關，所以可以寫成：

```cpp
// Your runtime beats 100.00 % of cpp submissions.
// Your memory usage beats 84.34 % of cpp submissions.

int countVowelPermutation(int n) {
    const int M = 1e9 + 7;
    long a = 1, e = 1, i = 1, o = 1, u = 1;

    for (int k = 2; k <= n; ++k) {
        long aa = (e + i + u) % M;
        long ee = (a + i) % M;
        long ii = (e + o) % M;
        long oo = i;
        long uu = (i + o) % M;
        a = aa;
        e = ee;
        i = ii;
        o = oo;
        u = uu;
    }

    return (a + e + i + o + u) % M;
}
```
