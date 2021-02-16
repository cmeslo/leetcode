# 91. Decode Ways

## Recursive (91_01.cpp)

```cpp
class Solution {
public:
    int numDecodings(string s) {
        vector<int> mem(s.length(), -1);
        return dfs(s, 0, mem);
    }
    
private:
    int dfs(const string& s, int i, vector<int>& mem) {
        int n = s.length();
        if (i >= n) return 1;
        if (s[i] == '0') return 0;
        if (mem[i] != -1) return mem[i];
        
        mem[i] = dfs(s, i + 1, mem);
        
        if (i + 1 < n) {
            if ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
                mem[i] += dfs(s, i + 2, mem);
        }
        
        return mem[i];
    }
};
```

## DP

### DP with O(n) space

#### 反向：
```cpp
int numDecodings(string s) {
    int n = s.length();

    if (n == 0 || s[0] == '0') return 0;

    vector<int> dp(n + 1);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') continue;
        dp[i] = dp[i + 1];
        if (i + 1 < n && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
            dp[i] += dp[i + 2];
    }

    return dp[0];
}
```

#### 正向 （因為 s 要取 i - 1 坐標，所以不太好看）
```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (valid(s, i - 1))
                dp[i] = dp[i - 1];
            if (i - 2 >= 0 && valid(s, i - 2, i - 1))
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
    
private:
    bool valid(const string& s, int i) {
        return s[i] != '0';
    }
    bool valid(const string& s, int i, int j) {
        int num = (s[i] - '0') * 10 + (s[j] - '0');
        return 10 <= num && num <= 26;
    }
};
```

### DP with O(1) space

#### 反向

```cpp
int numDecodings(string s) {
    int n = s.length();

    if (n == 0 || s[0] == '0') return 0;

    int dp1 = 1, dp2 = 0; // dp1 -> dp[i - 1], dp2 -> dp[i - 2]
    for (int i = n - 1; i >= 0; --i) {
        int tmp = s[i] == '0' ? 0 : dp1; // tmp -> dp[i]
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
            tmp += dp2;
        dp2 = dp1;
        dp1 = tmp;
    }

    return dp1;
}
```

#### 正向，寫得容易理解一點（91_02.cpp）
```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        
        int dp2 = 0, dp1 = 1; // dp2: dp[i - 2], dp1: dp[i - 1]
        for (int i = 0; i < n; ++i) {
            int dpi = 0;
            if (!valid(s[i]) && !valid(s[i - 1], s[i])) // invalid, eg: 00
                return 0;
            if (valid(s[i]))
                dpi = dp1;
            if (i - 1 >= 0 && valid(s[i - 1], s[i]))
                dpi += dp2;
            dp2 = dp1;
            dp1 = dpi;
        }
        return dp1;
    }
    
private:
    bool valid(const char c) {
        return c != '0';
    }
    bool valid(const char c1, const char c2) {
        int num = (c1 - '0') * 10 + (c2 - '0');
        return 10 <= num && num <= 26;
    }
};
```
