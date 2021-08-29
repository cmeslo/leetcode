# 97. Interleaving String

## Solution: DP

### 解釋

DP的定義：```dp[i][j] := 使用 A 的前 i 個字符，B 的前 j 個字符，是否可以組成 interleaving C```。

```
A: X X X X a
           ^--i
B: Y Y Y Y Y b
             ^--j
C: Z Z Z Z Z Z Z Z Z Z a
                       ^--i+j
```
如果 ```A[i]``` 與 ```C[i+j]``` 是相同字符，它們是否符合要求，就取決於上一步 ```dp[i-1][j]``` 是否符合要求，

```
A: X X X X
         ^--i-1
B: Y Y Y Y Y b
             ^--j
C: Z Z Z Z Z Z Z Z Z Z
                     ^--i+j-1
```

所以，得出狀態轉移方程：

```
dp[i][j] = A[i] == C[i + j] && dp[i - 1][j]

或者

dp[i][j] = B[j] == C[i + j] && dp[i][j - 1]
```

### Code

```cpp
bool isInterleave(string A, string B, string C) {
    int n = A.size(), m = B.size();
    if (n + m != C.size()) return false;

    A.insert(begin(A), '#');
    B.insert(begin(B), '#');
    C.insert(begin(C), '#');

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] && A[i] == C[i];

    for (int j = 1; j <= m; ++j)
        dp[0][j] = dp[0][j - 1] && B[j] == C[j];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i] == C[i + j] && dp[i - 1][j])
                dp[i][j] = true;
            else if (B[j] == C[i + j] && dp[i][j - 1])
                dp[i][j] = true;
        }
    }
    return dp[n][m];
}
```
