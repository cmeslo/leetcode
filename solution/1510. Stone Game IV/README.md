# 1510. Stone Game IV

## 1510_01.cpp

```cpp
// Your runtime beats 45.45 % of cpp submissions.

bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (dp[i - j * j]) continue;
            dp[i] = true;
            break;
        }
    }

    return dp[n];
}
```

## 1510_02.cpp

```cpp
// Your runtime beats 76.27 % of cpp submissions.

bool winnerSquareGame(int n) {
    static vector<int> dp(100001, -1); // -1 = unknow, 0 = lose, 1 = win

    if (dp[n] >= 0) return dp[n];

    for (int j = 1; j * j <= n; ++j)
        if (!winnerSquareGame(n - j * j))
            return dp[n] = 1;

    return dp[n] = 0;
}
```

or

```cpp
// Your runtime beats 80.64 % of cpp submissions.

class Solution {
public:
    bool winnerSquareGame(int n) {
        if (dp[n] > 0)
            return dp[n] == 1 ? false : true;
        
        for (int j = 1; j * j <= n; ++j)
            if (!winnerSquareGame(n - j * j)) {
                dp[n] = 2;
                return true;
            }
        
        dp[n] = 1;
        return false;
    }

private:
    int dp[100001]; // 0 = unknow, 1 = lose, 2 = win
};
```

or

```cpp
// Your runtime beats 95.71 % of cpp submissions.

bool winnerSquareGame(int n) {
    static int dp[100001]; // 0 = unknow, 1 = lose, 2 = win

    if (dp[n] > 0)
        return dp[n] == 1 ? false : true;

    for (int j = 1; j * j <= n; ++j)
        if (!winnerSquareGame(n - j * j)) {
            dp[n] = 2;
            return true;
        }

    dp[n] = 1;
    return false;
}
```
