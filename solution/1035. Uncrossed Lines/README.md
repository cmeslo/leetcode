# 1035. Uncrossed Lines

## 相當於 Longest Common Subsequence (LCS)

最長共用子序列問題，用DP求解

### C++

```cpp
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    nums1.insert(nums1.begin(), 0);
    nums2.insert(nums2.begin(), 0);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (nums1[i] == nums2[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    return dp[m][n];
}
```

or

```cpp
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nums1[i-1] == nums2[j-1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[m][n];
}


// x x x x i x

// x x x j x x
     
// dp[i][j] = dp[i-1][j-1] + (A[i] == B[j]) if A[i] == B[j]
//          = max(dp[i-1][j], dp[i][j-1]]) if A[i] != B[j]
```

### Java

```java
public int maxUncrossedLines(int[] A, int[] B) {
    int[][] dp = new int[A.length+1][B.length+1];
    
    for (int i = 1; i <= A.length; i++) {
        for (int j = 1; j <= B.length; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[A.length][B.length];
}
```

reference:
https://www.cxyxiaowu.com/2794.html
