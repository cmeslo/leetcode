# 97. Interleaving String

## Solution: DP 1

time: ```O(n^3)```

```cpp
bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    if (len1 + len2 != len3) return false;
    s1 = '#' + s1;
    s2 = '#' + s2;
    s3 = '#' + s3;

    vector<vector<vector<int>>> dp(len1 + 1, vector<vector<int>>(len2 + 1, vector<int>(len3 + 1, 0)));
    for (int i = 0; i <= len1; ++i)
        for (int j = 0 ; j <= len2; ++j)
            dp[i][j][0] = 1;

    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            for (int k = 1; k <= len3; ++k) {
                if (i + j != k) continue;

                if (s3[k] == s1[i])
                    dp[i][j][k] |= dp[i - 1][j][k - 1];

                if (s3[k] == s2[j])
                    dp[i][j][k] |= dp[i][j - 1][k - 1];
            }
        }
    }

    return dp[len1][len2][len3];
}

// a a b c c
// d b b c a
// a a d b b c b c a c

// x x x x c
// x x x x a
// x x x x x x x x x c

// dp[i][j][k] := 用 s1 的前 i 個、s2 的前 j 個字符，組成 s3 的前 k 個字符

// dp[i][j][k] |= dp[i][j][k - 1]

// if (s3[k] == s1[i])
//     dp[i][j][k] |= dp[i - 1][j][k - 1]
    
// if (s3[k] == s2[j])
//     dp[i][j][k] |= dp[i][j - 1][k - 1]
```

## Solution: DP 2 (推薦)

time: ```O(n^2)```

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
A: [X X X X] a
          ^--i-1
B: [Y Y Y Y Y b]
              ^--j
C: [Z Z Z Z Z Z Z Z Z Z] a
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
