# 474. Ones and Zeroes

## Solution 1: DP

### 解釋

最初以為是Greedy的問題、從size小至大選擇，但原來不是，例子：

```
Input: ["111","1000","1000","1000"], m = 9, n = 3

Expected: 3
```

既然不是Greedy，那就是DP了，其實這是、兩種容量的 ```0/1背包``` 問題

#### 狀態轉移方程：

```dp[k][i][j]``` 意思是考慮前 k 件物品，<strong>"數字0"</strong> 容量不超過 i、<strong>"數字1"</strong> 容量不超過 j 的最大價值（可以放的最大子集數量）

```cpp
if (i >= zeros && j >= ones)
    dp[k][i][j] = max(dp[k-1][i][j], dp[k-1][i-zeros][j-ones] + 1);
else
    dp[k][i][j] = dp[k-1][i][j];
```

### Code

這裡使用 "從後往前遍歷" 的方法，節省一個維度

```cpp
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (string& str : strs) {
        int zeros = 0, ones = 0;
        for (char& c : str) {
            if (c == '0')
                ++zeros;
            else
                ++ones;
        }

        for (int i = m; i >= zeros; --i) {
            for (int j = n; j >= ones; --j) {
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }
    return dp[m][n];
}
```

## Solution 2: DFS + memo

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->m = m;
        this->n = n;
        this->len = strs.size();
        memo.resize(len, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        vector<pair<int, int>> A(len);
        for (int i = 0; i < len; ++i) {
            int ones = 0, zeros = 0;
            for (char& c : strs[i]) {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }
            A[i] = {zeros, ones};
        }
        return dfs(A, 0, 0, 0);
    }
    
private:
    int len;
    int m, n;
    vector<vector<vector<int>>> memo;
    
    int dfs(vector<pair<int, int>>& A, int i, int zeros, int ones) {
        if (i == len) return 0;
        if (memo[i][zeros][ones] != -1) return memo[i][zeros][ones];
        
        int count = dfs(A, i + 1, zeros, ones);
        if (zeros + A[i].first <= m && ones + A[i].second <= n)
            count = max(count, dfs(A, i + 1, zeros + A[i].first, ones + A[i].second) + 1);
        
        return memo[i][zeros][ones] = count;
    }
};

// 10 0001 111001 1 0
//            i

// dfs(i + 1, zeros, ones, cur, ans)
// dfs(i + 1, zeros + 2, ones + 4, cur + 1, ans)
```
