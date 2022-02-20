# 834. Sum of Distances in Tree

```cpp
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.resize(n);
        count.resize(n);
        
        for (auto& e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }
    
private:
    vector<unordered_set<int>> tree;
    vector<int> res, count;
    
    void dfs(int root, int parent) {
        for (int i : tree[root]) {
            if (i == parent) continue;
            dfs(i, root);
            res[root] += res[i] + count[i];
            count[root] += count[i];
        }
        count[root]++; // add myself
    }
    
    void dfs2(int root, int parent) {
        for (int i : tree[root]) {
            if (i == parent) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
};
```
