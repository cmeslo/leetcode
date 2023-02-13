# 967. Numbers With Same Consecutive Differences

## Solution: DFS

```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        
        for (int x = 1; x <= 9; ++x)
            dfs(n - 1, k, x, res);
        
        return res;
    }
    
    void dfs(int n, int k, int x, vector<int>& res) {
        if (n == 0) {
            res.push_back(x);
            return;
        }
        
        int last = x % 10;
        
        if (last - k >= 0)
            dfs(n - 1, k, x * 10 + (last - k), res);
        
        if (k != 0 && last + k <= 9)
            dfs(n - 1, k, x * 10 + (last + k), res);
    }
};
```
