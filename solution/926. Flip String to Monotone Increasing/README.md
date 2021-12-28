# 926. Flip String to Monotone Increasing

## Solution 1: Two pass

### 解釋

```
   0 0 1 1 0
0: 0 0 1 2 2 ,從左至右掃瞄，看看全部變成0要多少次flip
1: 3 2 1 1 1 ,從右至左掃瞄，看看全部變成1要多少次flip

f[i][0] := 把[0:i]變成0要多少次flip
f[i][1] := 把[i:]變成1要多少次flip

0 0 1 1 0
0 1 1 1 1 -> f[0][0] + f[1][1] = 2
0 0 1 1 1 -> f[1][0] + f[2][1] = 1
```

### Code

```cpp
int minFlipsMonoIncr(string s) {
    int n = s.size();
    vector<int> f0(n), f1(n);
    f0[0] = s[0] == '1';
    f1[n - 1] = s[n - 1] == '0';
    for (int i = 1; i < n; ++i) {
        f0[i] = f0[i - 1] + (s[i] == '1');
        f1[n - i - 1] = f1[n - i] + (s[n - i - 1] == '0');
    }

    int ans = min(f0[n - 1], f1[0]); // 全0 或者 全1
    for (int i = 0; i + 1 < n; ++i)
        ans = min(ans, f0[i] + f1[i + 1]);
    return ans;
}
```

or

```cpp
int minFlipsMonoIncr(string s) {
    int n = s.size();
    s = '0' + s + '1';
    vector<int> left(n + 2), right(n + 2);
    for (int i = 1; i <= n; ++i) {
        left[i] = left[i - 1] + (s[i] == '1');
        right[n - i + 1] = right[n - i + 2] + (s[n - i + 1] == '0');
    }
    // for (int i = n; i >= 1; --i)
    //     right[i] = right[i + 1] + (s[i] == '0');

    int res = n;
    for (int i = 1; i <= n + 1; ++i) {
        res = min(res, left[i - 1] + right[i]);
    }
    return res;
}
 
// _ 0 0 1 1 0 _
// 0 1 2 3 4 n n+1
```

## Solution 2: DP

### 解釋

```
x x x x x x [x]

dp[i][0] := 範圍 [0:i]，把 s[i] 改為以 0 結尾所要的最少 Flip 次數
dp[i][1] := 範圍 [0:i]，把 s[i] 改為以 1 結尾所要的最少 Flip 次數

if (s[i] == '0')
    dp[i][0] = dp[i-1][0]
    dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1
if (s[i] == '1')
    dp[i][0] = dp[i-1][0] + 1
    dp[i][1] = min(dp[i-1][0], dp[i-1][1])
```

### Code

```cpp
int minFlipsMonoIncr(string s) {
    int dp0 = 0, dp1 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0')
            dp1 = min(dp0, dp1) + 1;
        else {
            dp1 = min(dp0, dp1);
            dp0 = dp0 + 1;
        }
    }
    return min(dp0, dp1);
}
```

可以簡化成

```cpp
int minFlipsMonoIncr(string s) {
    int dp0 = 0, dp1 = 0;
    for (char& c : s) {
        dp1 = min(dp0, dp1) + (c == '0');
        dp0 = dp0 + (c == '1');
    }
    return min(dp0, dp1);
}
```
