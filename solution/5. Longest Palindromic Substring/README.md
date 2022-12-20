# 5. Longest Palindromic Substring

## Solution 1: 中心拓展法 (5_01.cpp)
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        
        pair<int, int> ans = {0, 1}; // {start, len}
        for (int i = 0; i < s.length(); ++i) {
            auto str1 = getPalindrome(s, i, i + 1);
            auto str2 = getPalindrome(s, i - 1, i + 1);
            ans = str1.second > ans.second ? str1 : ans;
            ans = str2.second > ans.second ? str2 : ans;
        }

        return s.substr(ans.first, ans.second);
    }

private:
    pair<int, int> getPalindrome(string& s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l, ++r;
        }
        return {l + 1, r - l - 1};
    }
};
```

## Solution 2: DP (5_02.cpp)

```cpp
string longestPalindrome(string s) {
    int n = s.size();
    int start = 0, len = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i + l - 1 <= n; ++i) {
            int j = i + l - 1;

            if (l == 1)
                dp[i][i] = 1;
            else if (l == 2)
                dp[i][j] = s[i - 1] == s[j - 1] ? 2 : 0;
            else if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1])
                dp[i][j] = dp[i + 1][j - 1] + 2;

            if (dp[i][j] > len) {
                len = dp[i][j];
                start = i - 1;
            }
        }
    }
    return s.substr(start, len);
}
```
