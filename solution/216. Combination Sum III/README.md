# 216. Combination Sum III

Similar problem:

- [39. Combination Sum](https://leetcode.com/problems/combination-sum/description/)
- [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)

## Solution: DFS (216.cpp)

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(k, n, 1, cur, ans);
        return ans;
    }
    
private:
    void dfs(int k, int n, int start, vector<int>& cur, vector<vector<int>>& ans) {
        if (k == 0) {
            if (n == 0) ans.push_back(cur);
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            if (i > n) return;
            cur.push_back(i);
            dfs(k - 1, n - i, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};
```
