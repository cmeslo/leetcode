class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> res(n);
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n);
        
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            inDegree[b]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (inDegree[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front(); q.pop();
                for (int next : adj[node]) {
                    for (int ancestor : res[node])
                        res[next].insert(ancestor);
                    res[next].insert(node);
                    if (--inDegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = vector<int>(res[i].begin(), res[i].end());
        return ans;
    }
};
