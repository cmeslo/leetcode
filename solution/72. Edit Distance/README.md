# 72. Edit Distance

## Solution 1

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        _d = vector<vector<int>>(l1+1, vector<int>(l2+1, -1));
        return minDist(word1, word2, l1, l2);
    }
private:
    vector<vector<int>> _d;
    int minDist(const string& word1, const string& word2, int l1, int l2) {
        if (word1 == word2) return 0;
        
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;
        
        if (_d[l1][l2] >= 0) return _d[l1][l2];
        
        int ans = 0;
        if (word1[l1-1] == word2[l2-1]) {
             ans = minDist(word1, word2, l1-1, l2-1);
        } else {
            ans = 1 + min(
                min(minDist(word1, word2, l1, l2-1), // insert
                    minDist(word1, word2, l1-1, l2)), // remove
                minDist(word1, word2, l1-1, l2-1) //replace
            );
        }
        return _d[l1][l2] = ans;
    }
};
```

## Solution 2: DP

```
dp[i][j] := minimum number of operations to make word1[:i] = word2[:j]

dp[i][j] = dp[i-1][j-1] if word1[i] == word2[j]
           min(dp[i-1][j], dp[i][j-1]) + 1 if word1[i] != word2[j]

x x s
x x x x r
```

```cpp
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= n; ++j)
        dp[0][j] = j;
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int r = word1[i-1] != word2[j-1];
            dp[i][j] = min(dp[i-1][j-1] + r,
                            min(dp[i-1][j], dp[i][j-1]) + 1); 
        }
    }
    return dp[m][n];
}
```
