class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            ++inDegree[a];
            ++inDegree[b];
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (inDegree[i] <= 1)
                q.push(i);
        
        int count = n;
        while (count > 2) {
            count -= q.size();
            for (int i = q.size(); i > 0; --i) {
                int node = q.front(); q.pop();
                --inDegree[node];
                for (int next : adj[node]) {
                    if (inDegree[next] == 0) continue;
                    if (--inDegree[next] == 1) {
                        q.push(next);
                    }
                }
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
