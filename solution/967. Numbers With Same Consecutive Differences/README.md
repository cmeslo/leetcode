# 967. Numbers With Same Consecutive Differences

## Solution 1: DFS

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

## Solution 2: BFS

```cpp
vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int len = 2; len <= n; ++len) {
        vector<int> tmp;
        for (int x : res) {
            int y = x % 10;
            if (y - k >= 0)
                tmp.push_back(x * 10 + y - k);
            if (k > 0 && y + k <= 9)
                tmp.push_back(x * 10 + y + k);
        }
        res = tmp;
    }
    return res;
}
```
