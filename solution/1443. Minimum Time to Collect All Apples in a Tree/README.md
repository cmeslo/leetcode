# 1443. Minimum Time to Collect All Apples in a Tree

## Solution: DFS

### 寫法一： 2 次 DFS

```cpp
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<unordered_set<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        int apple_cnt = dfs(adj, hasApple, 0, -1);
        
        int res = 0;
        dfs2(adj, 0, -1, res);
        return res - 1;
    }

    int dfs(vector<unordered_set<int>>& adj, vector<bool>& hasApple, int node, int parent) {
        int cnt = hasApple[node];
        vector<int> del;
        for (int next : adj[node]) {
            if (next == parent) continue;
            int child_cnt = dfs(adj, hasApple, next, node);
            if (child_cnt == 0)
                del.push_back(next);
            cnt += child_cnt;
        }

        for (int next : del)
            adj[node].erase(next);

        return cnt;
    }

    void dfs2(vector<unordered_set<int>>& adj, int node, int parent, int& res) {
        ++res;
        for (int next : adj[node]) {
            if (next == parent) continue;
            dfs2(adj, next, node, res);
            ++res;
        }
    }
};
```

### 寫法二： 1 次 DFS (推薦)

```cpp
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(adj, hasApple, 0, -1, res);
        return res - 1; // 第一次進入 0 節點不算
    }

    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int node, int parent, int& res) {
        ++res; // 第一次踩這個節點
        int apple_cnt = hasApple[node];
        for (int next : adj[node]) {
            if (next == parent) continue;
            int old_res = res;
            int cnt = dfs(adj, hasApple, next, node, res);
            ++res; // dfs完回來, 再踩一次這個點
            if (cnt == 0) { // 這棵子樹沒有蘋果
                res = old_res; // 所以這棵子樹下走過的步數都作廢
            }
            apple_cnt += cnt;
        }
        return apple_cnt;
    }
};
```
