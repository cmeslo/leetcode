# 639. Decode Ways II

## Solution: DP

### 分析過程
```
x x x x x x x 2
dp[i] = dp[i-1]

x x x x x x 2 6
dp[i] += dp[i-2]

x x x x x x * 6
dp[i] += dp[i-2] * 2

x x x x x x * 7
dp[i] += dp[i-2] * 1

x x x x x x x *
dp[i] = dp[i-1] * 9

x x x x x x 1 *
dp[i] += dp[i-2] * 9 {* = 1-9}

x x x x x x 2 *
dp[i] += dp[i-2] * 6 {* = 1,2,3,4,5,6}

x x x x x x * *
dp[i] = dp[i-2] * 15

11,12,...,19 = 9
21,22,...,26 = 6
9 + 6 = 15
```

### Code

```cpp
int numDecodings(string s) {
    const int M = 1e9 + 7;
    int n = s.size();
    s.insert(s.begin(), '#');

    vector<long> dp(n + 1);
    dp[0] = 1;
    if (s[1] == '*')
        dp[1] = 9;
    else
        dp[1] = s[1] == '0' ? 0 : 1;

    for (int i = 2; i <= n; ++i) {
        if (s[i] == '*') {
            dp[i] = dp[i-1] * 9;
            if (s[i - 1] == '1')
                dp[i] += dp[i-2] * 9;
            else if (s[i - 1] == '2')
                dp[i] += dp[i-2] * 6;
            else if (s[i - 1] == '*')
                dp[i] += dp[i-2] * 15;
        } else {
            if (s[i] != '0')
                dp[i] = dp[i-1];
            if (s[i-1] == '*')
                dp[i] += dp[i-2] * (s[i] <= '6' ? 2 : 1);
            else if ((s[i-1] == '1' && s[i] <= '9') || (s[i-1] == '2' && s[i] <= '6'))
                dp[i] += dp[i-2];
        }
        dp[i] %= M;
    }
    return dp[n];
}
```

由於 ```dp[i]``` 只和 ```dp[i-1]``` 和 ```dp[i-2]``` 有關，所以可以進行空間壓縮：

```cpp
class Solution {
public:
    int numDecodings(string s) {
        const int kMod = 1e9 + 7;
        int n = s.size();
        
        long dpi_2 = 0, dpi_1 = 1; //dpi_2 = dp[i-2], dpi_1 = dp[i-1]
        for (int i = 1; i <= n; ++i) {
            long dpi = 0;
            dpi += dpi_1 * ways(s, i-1);
            dpi += dpi_2 * ways(s, i-2, i-1);
            dpi %= kMod;
            dpi_2 = dpi_1;
            dpi_1 = dpi;
        }
        return dpi_1;
    }
    
private:
    int ways(string& s, int i) {
        if (s[i] == '*') return 9;
        if (s[i] == '0') return 0;
        return 1;
    }
    
    int ways(string& s, int i, int j) {
        if (i < 0) return 0;
        
        if (s[i] == '*' && s[j] == '*') {
            return 15;
        } else if (s[i] == '*') {
            return ('0' <= s[j] && s[j] <= '6' ? 2 : 1);
        } else if (s[j] == '*') {
            if (s[i] == '1')
                return 9;
            else if (s[i] == '2')
                return 6;
        } else {
            int num = (s[i] - '0') * 10 + (s[j] - '0');
            if (10 <= num && num <= 26)
                return 1;
        }
        return 0;
    }
};
```
