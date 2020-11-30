class Solution {
public:
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
};
