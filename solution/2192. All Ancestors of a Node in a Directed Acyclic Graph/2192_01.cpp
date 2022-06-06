class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n);
        vector<vector<int>> G(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            G[a].push_back(b);
            inDegree[b]++;
        }
        
        vector<bitset<1001>> ans(n);

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front(); q.pop();
                for (int next : G[node]) {
                    ans[next] |= ans[node];
                    ans[next].set(node);
                    if (--inDegree[next] == 0)
                        q.push(next);
                }
            }
        }
        
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ans[i][j])
                    res[i].push_back(j);
            }
            // cout << ans[i].count() << endl;
        }
        return res;
    }
};
