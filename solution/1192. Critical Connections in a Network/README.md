# 1192. Critical Connections in a Network

## Solution: Tarjan's Algorithm

- time: ```O(V+E)```

```cpp
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.resize(n);
        for (auto& conn : connections) {
            g[conn[0]].push_back(conn[1]);
            g[conn[1]].push_back(conn[0]);
        }
        
        tags.resize(n, -1);
        dfs(0, -1, 0);
        return ans;
    }
    
private:
    vector<vector<int>> g;
    vector<int> tags;
    vector<vector<int>> ans;

    int dfs(int cur, int parent, int tag) {
        tags[cur] = tag;
        
        for (int next : g[cur]) {
            if (next == parent)
                continue;
            else if (tags[next] == -1)
                tags[cur] = min(tags[cur], dfs(next, cur, tag + 1));
            else
                tags[cur] = min(tags[cur], tags[next]);
        }
        
        if (tags[cur] == tag && cur != 0)
            ans.push_back({parent, cur});
        return tags[cur];
    }
};
```
