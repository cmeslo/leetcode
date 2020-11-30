# 310. Minimum Height Trees

解釋：從邊緣（葉子）開始往中心剪枝，到不能再剪時就是 <strong>最小樹高</strong>。

## 310_01.cpp

用 "入度" 來找葉子，需要多用 O(n) 空間保存 "入度"

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
    {
        if (n == 1) return { 0 };

        vector<int> degrees(n);
        vector<unordered_set<int>> graph = makeGraph(n, edges, degrees);
        queue<int> leaves;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) leaves.push(i);
        }

        while (n > 2) {

            int curleaves = leaves.size();
            n -= curleaves;

            for (int i = 0; i < curleaves; ++i) {
                int leap = leaves.front();
                leaves.pop();
                for (auto neighbor : graph[leap]) {
                    graph[neighbor].erase(leap);
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) leaves.push(neighbor);
                }
            }
        }
        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }

    vector<unordered_set<int>> makeGraph(int n, vector<pair<int, int>>& edges, vector<int>& degrees)
    {
        vector<unordered_set<int>> graph(n, unordered_set<int>());

        for (auto edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
            degrees[edge.first]++;
            degrees[edge.second]++;
        }
        return graph;
    }
};
```

## 310_02.cpp

用 "出度" 來找葉子

```cpp
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n < 2) return {0};

    vector<unordered_set<int>> g(n);
    for (const auto& edge : edges) {
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
    }

    queue<int> leaves;
    for (int i = 0; i < n; ++i)
        if (g[i].size() == 1)
            leaves.push(i);

    while (n > 2) {
        int size = leaves.size();
        n -= size;

        for (int i = 0; i < size; ++i) {
            int leaf = leaves.front(); leaves.pop();
            int next = *g[leaf].begin();
            g[next].erase(leaf);
            if (g[next].size() == 1) leaves.push(next);
        }
    }

    vector<int> res;
    while (!leaves.empty()) {
        res.push_back(leaves.front());
        leaves.pop();
    }
    return res;
}
