class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> res(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(adj, labels, 0, -1, res);
        return res;
    }

    vector<int> dfs(vector<vector<int>>& adj, string& labels, int node, int parent, vector<int>& res) {
        vector<int> cnt(26);
        for (int next : adj[node]) {
            if (next == parent) continue;
            auto cur = dfs(adj, labels, next, node, res);
            for (int i = 0; i < 26; ++i)
                cnt[i] += cur[i];
        }
        res[node] = ++cnt[labels[node] - 'a'];
        return cnt;
    }
};
