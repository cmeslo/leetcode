# 1770. Maximum Score from Performing Multiplication Operations

## Solution 1: DFS + memorization

```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        memo.resize(m, vector<int>(m, INT_MIN));
        return dp(nums, multipliers, 0, nums.size() - 1);
    }
    
private:
    vector<vector<int>> memo;
    
    int dp(vector<int>& A, vector<int>& M, int l, int r) {
        int i = A.size() - (r - l + 1);
        
        if (i >= M.size()) return 0;
        
        if (memo[l][i] != INT_MIN) return memo[l][i];
        
        return memo[l][i] = max(M[i] * A[l] + dp(A, M, l + 1, r),
                                M[i] * A[r] + dp(A, M, l, r - 1));
    }
};
```
