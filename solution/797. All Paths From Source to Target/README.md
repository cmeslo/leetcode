# 797. All Paths From Source to Target

## Solution: DFS

```cpp
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> cur{0};
        dfs(graph, 0, cur, res);
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& G, int node, vector<int>& cur, vector<vector<int>>& res) {
        if (node == G.size() - 1) {
            res.push_back(cur);
            return;
        }
        
        for (int next : G[node]) {
            cur.push_back(next);
            dfs(G, next, cur, res);
            cur.pop_back();
        }
    }
};
```
